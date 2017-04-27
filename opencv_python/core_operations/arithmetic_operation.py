'''
Coded by luke on 27th April 2017, aiming to familarize the arithmetic operations for image provided by opencv wth python

'''

import numpy as np
import cv2


#blend two images 
img1 = cv2.imread('')
img2 = cv2.imread('')

dst = cv2.addWeighted(img1,0.7,img2,0.3,0)

cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()


#bitwise operation
img1 = cv2.imread('messi.jpg')
img2 = cv2.imread('opencv_logo.png')

#I want to put logo on top-left corner,so i create a ROI
rows,cols,channels = img2.shape
roi = img1[0:rows,0:cols]

#Now create a mask of logo and create it inverse mask also
img2gray = cv2.cvtColor(img2,cv.COLOR_BRG2GRAY)
ret,mask = cv2.threshold(img2gray,10,255,cv2.THRESH_BINARY)

mask_inv = cv2.bitwise_not(mask)

#Now black_out the area of logo in ROI
img1_bg = cv2.bitwise_and(roi,roi,mask=mask_inv)

#take only region of logo from logo image
img2_fg = cv2.bitwise_and(img2,img2,mask=mask)

#put only in ROI and modify the main image
dst = cv2.add(img1_bg,img_fg)

img1[0:rows,0:cols] = dst

cv2.imshow('res',img1)
cv2.waitKey(0)
cv2.destroyAllWindows()
