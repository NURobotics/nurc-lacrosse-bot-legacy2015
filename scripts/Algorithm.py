#!/usr/bin/env python

import cv2
import numpy as np

import IPython

class Algorithm(object):
  """General base class functionality for any Algorithm objects"""
  def __init__(self):
    pass

  def algorithm(self, im):
    pass

  def __call__(self, im):
    return self.algorithm(im)


class Centroid(Algorithm):

  def __init__(self):
    super(Centroid, self).__init__()

  def algorithm(self, im):
    """Calculate the centroid of an input image"""
    if isinstance(im, np.ndarray) and len(im.shape) >= 2:
      c = cv2.moments(im)
      if abs(c['m00']) > 0.001:
        return (int(c['m10']/c['m00']), int(c['m01']/c['m00']))
      else:
        return (-1, -1)


class CCL(Algorithm):

  def __init__(self):
    super(CCL, self).__init__()

  def algorithm(self, im):
    if isinstance(im, np.ndarray) and len(im.shape) >= 2:
      contours, hierarchy = cv2.findContours(im, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)

      if len(contours) > 0:
        max_contour = max(contours, key=len)
        return tuple(np.mean(max_contour[:,0,:], axis=0).astype(int))
      else:
        return (-1, -1)

if __name__ == '__main__':
  # Algorithm main test sequences
  pass
