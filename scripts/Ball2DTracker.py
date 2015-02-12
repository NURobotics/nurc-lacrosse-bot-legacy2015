#!/usr/bin/env python

import cv2
import numpy as np
from Tracker import Tracker
from Filter import ThresholdFilter, KalmanFilter
from Algorithm import Centroid

class Ball2DTracker(Tracker):
  
  def __init__(self):
    super(Ball2DTracker, self).__init__()
    self.threshold_filter = ThresholdFilter( np.array([150, 50, 50], dtype=np.uint8), np.array([175, 255, 255], dtype=np.uint8) )
    
    # Setup the Kalman Filter noise matrices
    self.Q = (10**-3) * np.eye(4,4)
    self.R = (10**-1) * np.eye(2,2)
    self.kalman_filter = KalmanFilter(self.Q, self.R)
    self.centroid_algo = Centroid()
    self.transformed_image = np.copy( self.image )
    self.centroid = self.centroid_algo(self.threshold_filter(self.transformed_image))
  
  def captureImageFrame(self):
    super(Ball2DTracker, self).captureImageFrame()
    if self.valid:
      self.transformed_image = np.copy( self.image )
      self.transformed_image = cv2.resize(self.transformed_image, (0,0), self.transformed_image, 0.5, 0.5, cv2.INTER_LANCZOS4)
      self.transformed_image = cv2.GaussianBlur(self.transformed_image, (9,9), 2, self.transformed_image, 2)
      self.transformed_image = cv2.cvtColor(self.transformed_image, cv2.COLOR_BGR2HSV)
      self.transformed_image = self.threshold_filter(self.transformed_image)
      self.centroid = self.centroid_algo(self.transformed_image)
      self.transformed_image = cv2.cvtColor(self.transformed_image, cv2.cv.CV_GRAY2BGR)
      self.centroid = tuple([2*i for i in self.centroid])
      filtered = self.kalman_filter(self.centroid)
      self.centroid = (int(filtered[0,0]), int(filtered[1,0]))
      cv2.circle(self.transformed_image, self.centroid, 2, (255, 0, 0), -1)
      cv2.circle(self.image, self.centroid, 2, (255, 0, 0), -1)

if __name__ == '__main__':
  # Ball Tracker Tests
  b2dt = Ball2DTracker()
  while cv2.waitKey(1) == -1 and b2dt.valid:
    cv2.imshow("Transformed Image", b2dt.transformed_image)
    cv2.imshow("Original Image", b2dt.image)
    b2dt.captureImageFrame()
  cv2.destroyAllWindows()
