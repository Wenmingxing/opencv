'''
Coded by luke on 27th April 2017, aiming to convert to cv2.CV_8U

'''
import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('box.png',0)

#output dtype = cv2.CV_8U
sobelx8u = cv2.Sobel(img,cv2.CV_8U,1,0,ksize=5)

#output dtype = cv2.cv_64f. then take its absolute and convert to cv2.cv8u

sobelx64f = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=5)

abs_sobel64f = np.absolute(sobel64f)
sobel_8u = np.uint8(abs_sobel64f)


plt.subplot(1,3,1),plt.imshow(img,'gray')
plt.title('original'),plt.xticks([]),plt.yticks([])

plt.subplot(1,3,2),plt.imshow(sobelx8u,'gray')
plt.title('sobel cv_8u')

plt.subplot(1,3,3),plt.imshow(sobel_8u,'gray')
plt.title('sobel abs(cv_64f)')

plt.show()
