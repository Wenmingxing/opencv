'''
Coded by luke on 27th April 2017 for building the borderd for image with different methods provided by opencv with python
'''

import numpy as np
import cv2
from matplotlib import pyplot as plt

img1 = cv2.imread('roi.jpg')

replicate = cv2.copyMakeBorder(img1,10,10,10,10,cv2.BORDER_REPLICATE)
reflect = cv2.copyMakeBorder(img1,10,10,10,10,cv2.BORDER_REFLECT)
reflect101 = cv2.copyMakeBorder(img1,10,10,10,10,cv2.BORDER_REFLECT_101)
wrap = cv2.copyMakeBorder(img1,10,10,10,10,cv2.BORDER_WRAP)
constant = cv2.copyMakeBorder(img1,10,10,10,10,cv2.BORDER_CONSTANT,value =(0,0,255))

plt.subplot(231),plt.imshow(img1,'gray'),plt.title('original')
plt.subplot(232),plt.imshow(replicate,'gray'),plt.title('replicate')
plt.subplot(233),plt.imshow(reflect,'gray'),plt.title('reflect')
plt.subplot(234),plt.imshow(reflect101,'gray'),plt.title('reflect101')
plt.subplot(235),plt.imshow(wrap,'gray'),plt.title('wrap')
plt.subplot(236),plt.imshow(constant,'gray'),plt.title("constant")

plt.show()
