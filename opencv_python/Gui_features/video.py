'''
Coded by luke on 27th April 
Aiming to familirize the video class provide by python opencv

'''
import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while(cap.isOpened()):
	#capture the video frame by frame
	ret,frame = cap.read()

	#our operations on the frame come here
	gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)

	#Display the resulting frames
	cv2.imshow('frame',gray)
	
	if cv2.waitKey(1) == ord('q'):
		break

#when everything done,release the capture
cap.release()
cv2.destroyAllWindows()
