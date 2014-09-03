#!/usr/bin/env python

import cv2
import numpy as np
import timeit
from Filter import ThresholdFilter


def case_1(image=cv2.imread('../images/invader_zim.jpg'), threshold_filter=ThresholdFilter(np.array([150,50,50], dtype=np.uint8), np.array([175,255,255], dtype=np.uint8))):
  timage = cv2.resize(image, (0,0), image, 0.5, 0.5, cv2.INTER_LANCZOS4)
  timage = cv2.GaussianBlur(timage, (9, 9), 2, timage, 2)
  timage = threshold_filter(timage)

if __name__ == '__main__':
  t = timeit.timeit('case_1()', number=1000, setup='from __main__ import case_1')
  print 'Total time of %d', t
