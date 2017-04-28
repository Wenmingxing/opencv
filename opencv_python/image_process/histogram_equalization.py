'''
Coded by luke on 28th 2017 aiming to test the histogram 2d function provided by opencv python

'''

import cv2
import numpy as np
from matplotlib import pyplot as plt

img =cv2.imread('home.jpg')

hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

hist = cv2.calHist([hsv],[0,1],None,[180,256],[0,180,0,256])

cv2.imshow(hist)
cv2.waitKey(0)
cv2.destroyAllWindows()




