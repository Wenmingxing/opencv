'''
coded by luke on 27th April 2017 aiming to detect the edges in images

'''
import cv2
import numpy as np

from matplotlib import pypot as plt

img = cv2.imread('messi.jpg',0)
edges = cv2.Canny(img,100,200)

plt.subplot(121),plt.imshow(img,'gray')
plt.title('original'),plt.xticks([]),plt.yticks([])

plt.subplot(122),plt.imshow(edges,'gray')
plt.title('Edge'),plt.xticks([]),plt.yticks([])

plt.show()
