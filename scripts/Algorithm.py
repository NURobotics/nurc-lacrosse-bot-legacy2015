#!/usr/bin/env python

import cv2
import numpy as np

class Algorithm(object):
  """General base class functionality for any Algorithm objects"""
  def __init__(self):
    pass
  
  def algorithm(self, i):
    pass
  
  def __call__(self, i):
    return self.algorithm(i)


class Centroid(Algorithm):
  
  def __init__(self):
    super(Centroid, self).__init__()
  
  def algorithm(self, i):
    """Calculate the centroid of an input image"""
    if isinstance(i, np.ndarray) and len(i.shape) >= 2:
      c = cv2.moments(i)
      if abs(c['m00']) > 0.001:
        return (int(c['m10']/c['m00']), int(c['m01']/c['m00']))
      else:
        return (0, 0)

if __name__ == '__main__':
  # Algorithm main test sequences
  pass
