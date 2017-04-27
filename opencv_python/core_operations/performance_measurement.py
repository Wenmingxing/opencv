'''
Coded by luke on 27th April 2017 aiming to test the performance of the functionality

'''
import numpy as np
import cv2

img = cv2.imread('roi.jpg')

e1 = cv2.getTickCount()

for i in xrange(5,49,2):
	img1 = cv2.medianBlur(img,i)

e2 = cv2.getTickCount()

t = (e2-e1)/cv2.getTickFrequency()
print t
