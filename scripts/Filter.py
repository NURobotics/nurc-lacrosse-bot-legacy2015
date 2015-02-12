#!/usr/bin/env python

import cv2
import numpy as np
import time


class Filter(object):
  
  def __init__(self):
    pass
  
  def filter(self, image):
    pass
  
  def __call__(self, image):
    return self.filter(image)


class ThresholdFilter(Filter):
  
  modes = ('RANGE', 'TARGET')
  
  def __init__(self, lower_bound=np.array([0, 0, 0], np.uint8), upper_bound=np.array([0, 0, 0], np.uint8),  target=np.array([0, 0, 0], np.uint8), mode='RANGE', tolerance=0.0):
    # Just a formality
    super(ThresholdFilter, self).__init__()
    if mode not in ThresholdFilter.modes:
      self.mode = 'RANGE'
    else:
      self.mode = mode
    self.lower_bound = lower_bound
    self.upper_bound = upper_bound      
    self.target = target
    self.tolerance = tolerance if tolerance >= 0.0 else 0.0
  
  def filter(self, image):
    if self.mode == 'RANGE':
      return cv2.inRange(image, self.lower_bound, self.upper_bound)
    elif self.mode == 'TARGET':
      pass

class KalmanFilter(Filter):
  
  def __init__(self, Q, R):
    super(KalmanFilter, self).__init__()
    self.discrete_times = [0., time.time()]
    self.discrete_positions = [(0., 0.), (0., 0.)]
    dt = 0.
    self.H = np.array([[1., 0., dt, 0.], [0., 1., 0., dt], [0., 0., 1., 0.], [0., 0., 0., 1.]], np.float32);
    self.F = np.array([[1.0, 0., 0., 0.], [0., 1., 0., 0.]], np.float32);
    
    # Setup the noise matrices Q and R
    if Q == None or R == None:
      self.Q = (10**-3)*np.eye(4,4, np.float32)
      self.R = (10**-1)*np.eye(2,2, np.float32)
    else:
      self.Q = Q.astype(np.float32)
      self.R = R.astype(np.float32)
    self.S = np.zeros([4,1], np.float32)
    self.P = np.zeros([4,4], np.float32)
  
  def filter(self, point):
    if type(point) == tuple or type(point) == list:
      self.discrete_times[0] = self.discrete_times[1]
      self.discrete_times[1] = time.time()
      self.discrete_positions[0] = self.discrete_positions[1]
      self.discrete_positions[1] = tuple(point)
      velocity = (self.discrete_positions[1][0] - self.discrete_positions[0][0], self.discrete_positions[1][1] - self.discrete_positions[0][1])
      dt = self.discrete_times[1] - self.discrete_times[0]
      self.H[0,2] = self.H[1,3] = dt
      self.S = self.H * self.S
      self.P = self.H * self.P * np.transpose( self.H ) + self.Q
      kalman_gain = np.dot(np.dot(self.P, np.transpose( self.F )), np.linalg.pinv( np.dot(np.dot(self.F, self.P), np.transpose( self.F )) + self.R ))
      y = np.transpose( np.array([point[0], point[1], velocity[0], velocity[1]], np.float32) )
      self.S = self.S - np.dot(kalman_gain, (y - np.dot(self.F,self.S) ))
      self.P = np.dot((np.eye(4,4) - np.dot(kalman_gain, self.F)), self.P)
    return self.S

if __name__ == '__main__':
  # ThresholdFilter Main Tests
  tf = ThresholdFilter()  
