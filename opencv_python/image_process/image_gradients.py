'''
Coded by luke on 27th April 2017, aiming to test the image gradients

'''

#Find image gradients,edges

import cv2
import numpy as np

from matplotlib import pyplot as plt

img = cv2.imread('dave.jpg',0)

laplacian = cv2.Laplacian(img,cv2.CV_64F)
sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize = 5)
sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize = 5)

plt.subplot(2,2,1),plt.imshow(img,cmap='gray')
plt.title('original'),plt.xticks([]),plt.yticks([])

plt.subplot(2,2,2),plt.imshow(laplcian,cmap='gray')
plt.title('laplacian'),plt.xticks([]),plt.yticks([])

plt.subplot(2,2,3),plt.imshow(sobelx,'gray')
plt.title('sobel x'),plt.xticks([]),plt.yticks([])

plt.subplot(2,2,4),plt.imshow(sobely,'gray')
plt.title('soble y'),plt.xticks([]),plt.yticks([])

plt.show()
