'''
Coded by luke on 27th April 2017 aiming to finish the basic operations for the image

'''
import numpy as np
import cv2

img = cv2.imread('messi.jpg')

px = img[100,100]
print px

'''
blue = img [100,100,0]
print blue
'''

img[100,100] = [255]
print img[100,100]

#access image properties
print img.shape

print img.size

print img.dtype

#image ROI

ball = img[280:340,330:390]
img[273:333,100:160] = ball

#split and merging image channels
b,g,r = cv2.split(img)
img = cv2.merge(b,g,r)

b = img[:,:,0]

img[:,:,2] = 0




