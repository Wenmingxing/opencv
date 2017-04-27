'''
Coded by luke on 27th April 2017, aiming to test color space change functions in opencv 

'''

# object tracking,extract the blue object from a colorful frame abtained in video stream

import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while(True):
	#Take each frame
	rec,frame = cap.read()
	
	#convert BGR to HSV
 	hsv = cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)

	#define rang of blue color in hsv
	lower_blue = np.array([110,50,50])
	upper_blue = np.array([230,255,255])

	#Threshold the HSV image to get only blue colors
	mask = cv2.inRange(hsv,lower_blue,upper_blue)

	#BITWISE_AND mask and original image
	res = cv2.bitwise_and(frame,frame,mask=mask)

	cv2.imshow('frame',frame)
	cv2.imshow('mask',mask)
	cv2.imshow('res',res)

	if cv2.waitKey(1) == 27:
		break
cv2.destroyAllWindows()
