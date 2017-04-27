'''
Coded by luke on 27th April 2017 aiming to start the contours tutorials

'''

import numpy as np

import cv2

im = cv2.imread('roi.jpg')
imgray = cv2.cvtColor(im,cv2.COLOR_BRG2GRAY)
ret,thresh = cv2.threshold(imgray,127,255,0)
#FInd the contours in the binary image
contour,hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)


# draw the contours
cv2.drawContours(img,contours,-1,(0,255,0),3)



