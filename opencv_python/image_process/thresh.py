'''
Coded by lukeo n 27th April 2017 aiming to test the threshold functions provided by opencv with python

'''
#gloal thresh
import cv2
import numpy as np
from matplotlib import pyploy as plt

img = cv2.imread('gradient.png',0)

ret,thresh1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
ret,thresh2 = cv2.threshold(img,127,255,cv2.THRESH_BINARY_INV)
ret,thresh3 = cv2.threshold(img,127,255,cv2.THRESH_TRUNC)
ret,thresh4 = cv2.threshold(img,127,255,cv2.THRESH_TOZERO)
rec,thresh5 = cv2.threshold(img,127,255,cv2.THRESH_TOZERO_INV)

titles = ['original image','binary','binary_inv','trunc','tozero','tozero_inv']

images = [img,thresh1,thresh2,thresh3,thresh4,thresh5]

for i in xrange(6):
	plt.subplot(2,3,i+1),plt.imshow(image[i],'gray')
	plt.title(titles[i])
	plt.xticks([]),plt.yticks([])
	
plt.show()

#adaptive thresh
img = cv2.imread('dave.jpg',0)
img = cv2.medianBlur(img,5)

ret,th1 = cv2.threshold(img,127,255,cv2.THRESH_BINARY)

th2 = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,11,2)

th3 = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,cv2.THRESH_BINARY,11,2)

titles = ['original image','global threshold','adaptive threshold mean','adaptive threshold gaussian']
images = [img,th1,th2,th3]

for i in xrange(4):
	plt.subplot(2,2,i+1),plt.imshow(images[i],'gray')
	plt.title(titles[i])

plt.show()
