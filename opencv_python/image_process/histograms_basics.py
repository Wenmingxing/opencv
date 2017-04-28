'''
Coded by luke on 28th April 2017  aiming to familarize the basics for histograms in opencv python

'''
# Calculate the histogram with opencv function
import numpy as np
import cv2

img = cv2.imread('home.jpg',0)
hist = cv2.calHist([img],[0],None,[256],[0,256])

# histogram calculation in numpy
hist,bins = np.histogram(img.ravel(),256,[0,256])

# plotting histograms
# using matplotlib
from matplotlib import pyplot as plt
img = cv2.imread('home.jpg',0)
plt.hist(img.ravel(),256,[0,256])
plt.show()

# using opencv and application of mask
img = cv2.imread('home.jpg',0)

#create a mask
mask = np.zeros(img.shape(:2),np.uint8)

mask[100:300,100:400] = 255

masked_img = cv2.bitwise_and(img,img,mask=mask)

# calculate histogram with mask and without mask
# check third argument for mask
hist_full = cv2.calHist([img],[0],None,[256],[0,256])
hist_mask = cv2.calHist([img],[0],mask,[256],[0,256])

plt.subplot(221),plt.imshow(img,'gray')
plt.subplot(222),plt.imshow(mask,'gray')
plt.subplot(223),plt.imshow(mask_img,'gray')
plt.subplot(224),plt.plot(hist_hull),plt.plot(hist_mask)
plt.xlim([0,256])

plt.show()


