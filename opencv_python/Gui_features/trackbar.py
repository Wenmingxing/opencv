'''
Coded by luke on 27th April 2017 in order to familiarize the trackbar  function in opencv with python

'''

import numpy as np
import cv2

def nothing(x):
	pass

#create a black image, a window

img = np.zeros((300,512,3),np.uint8)
cv2.namedWindow('image')

#create  trackbar for color change
cv2.createTrackbar('r','image',0,255,nothing)
cv2.createTrackbar('g','image',0,255,nothing)
cv2.createTrackbar('b','image',0,255,nothing)

#create switch for on/off functionality
switch = '0: off \n1: ON'
cv2.createTrackbar(switch,'image',0,1,nothing)

while(1):
	cv2.imshow('image',img)
	k = cv2.waitKey(1)
	if k == 27:
		break
	
	#get current position of four trackbars
	r = cv2.getTrackbarPos('r','image')
	g = cv2.getTrackbarPos('g','image')
	b = cv2.getTrackbarPos('b','image')
	s = cv2.getTrackbarPos(switch,'image')

	if s == 0:
		img[:] = 0
	else:
		img[:] = [b,g,r]

	
cv2.destroyAllWindows()
