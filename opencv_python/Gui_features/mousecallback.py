'''
Coded by luke on 27th April 2017 aiming to complete a mouse callback function

'''

import cv2
import numpy as np

#mouse callback function
def draw_circle(event,x,y,flags,param):
	if event == cv2.EVENT_LBUTTONDBLCLK:
		cv2.circle(img,(x,y),100,(255,0,0),-1)

#create a black name, a window and bind the function to window
img = np.zeros((512,512,3),np.uint8)
cv2.namedWindow('image')
cv2.setMouseCallback('image',draw_circle)

while(True):
	cv2.imshow('image',img)
	if cv2.waitKey(20) == 27:
		break
cv2.destroyAllWindows()
