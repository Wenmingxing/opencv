'''Coded by luke on 27th April 2017
   Aiming toe study the opencv basic structure with python
'''

import numpy as np
import cv2

#load an color image in grayscale
img = cv2.imread('messi.jpg',0);

cv2.imshow('image',img);
k = cv2.waitKey(0)
if k == 27: #wait for ESC key to exit
	cv2.destroyAllWindows()
elif k == ord ('s'): # wait for 's' key to save and exit
	cv.imwrite("messigray.png",img)
	cv2.destroyAllWindows()


	
	


