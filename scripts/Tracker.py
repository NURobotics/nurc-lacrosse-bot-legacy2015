#/usr/bin/env python

import cv2
import numpy as np

class Tracker(object):
  
  def __init__(self):
    self.video_capture = cv2.VideoCapture(0)
    if self.video_capture.isOpened():
      self.valid, self.image = self.video_capture.read()
    else:
      self.image = np.empty( (600, 800, 3), float )
      self.valid = False
    self.previous_tick_count = self.current_tick_count = cv2.getTickCount()
    self.total_tick_count = 0
  
  def __del__(self):
    # Since OpenCV uses a binding interface should perform basic memory management
    self.video_capture.release()
  
  def setVideoCapture(self, capture):
    self.video_capture.open(capture)
    if isinstance(capture, str):
      self.image = np.empty( self.video_capture.get(cv2.cv.CV_CAP_PROP_FRAME_HEIGHT), self.video_capture.get(cv2.cv.CV_CAP_PROP_FRAME_WIDTH), 3 );
    else:
      self.image = np.empty( (600, 800, 3), float )
    return self.video_capture.isOpened()
  
  def captureImageFrame(self):
    if self.video_capture.isOpened():
      self.valid, self.image = self.video_capture.read()
      self.prev_tick_count = self.current_tick_count
      self.current_tick_count = cv2.getTickCount()
      self.total_tick_count += self.current_tick_count - self.prev_tick_count
  
  def getRuntime(self):
    return self.total_tick_count/cv2.getTickFrequency()
  


if __name__ == '__main__':
  # Unit tests
  tracker_test = Tracker()
  while cv2.waitKey(1) == -1 and tracker_test.valid:
    cv2.imshow("Tracker", tracker_test.image)
    tracker_test.captureImageFrame()
  cv2.destroyAllWindows()
  
