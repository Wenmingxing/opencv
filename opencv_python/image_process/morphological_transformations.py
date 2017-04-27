'''
Coded by luke on 27th April 2017 to test the morphological transformations

'''

import cv2
import numpy as np

img = cv2.imread('j.png',0)
kernel = np.ones((5,5),np.uint8)
erosion = cv2.erode(img,kernel,iterations = 1)

dilation = cv2.dilate(img,kernel,iterations = 1)

# opening is dilation + erosion to remove noise
opening = cv2.morphologEx(img,cv2.MORPH_OPEN,kernel)

# closing is erosion + dilation
closing = cv2.morphologyEx(img,cv2.MORPH_CLOSE,kernel)

# morphological gradient= the difference between dilation and erosion of the image
gradient = cv2.morphologyEx(img,cv2.MORPH_GRADIENT,kernel)





