'''
Coded by luke on 27th April 2017 aiming to test the backprojection function in histograms using to do object segmentation

'''

import cv2
import numpy as np

roi = cv2.imread('rose_red.png')
hsv = cv2.cvtColor(roi,cv2.COLOR_BGR2HSV)

target = cv2.imread('rose.png')
hsvt = cv2.cvtColor(target,cv2.COLOR_BGR2HSV)

#Calculate the object histogram
roihist = cv2.calcHist([hsv],[0,1],None,[180,256],[0,180,0,256])

#Normalize histogram and apply backprojection
cv2.normalize(roihist,rohist,0,255,cv2.NORM_MINMAX)
dst = cv2.calcBackProjct([hsvt],[0,1],roihist,[0,180,0,256],1)

#Now convolute withcircular disc
disc = cv2.getStructuringELement(cv2.MORPH_ELLIPSE,(5,5))

CV2.filter2D(dst,-1,disc,dst)

#threshold and binary and
ret,thresh = cv2.threshold(dst,50,255,0)
thresh = cv2.merge((thresh,thresh,thresh))
res = cv2.bitwise_and(traget,thresh)

res = np.vstack((target,thresh,res))
cv.imwrite('res.jpg',res)


