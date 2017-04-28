'''
Coded by luke on 28th April 2017 aiming to test the multiple matching function in opencv python

'''

import cv2
import numpy as np
from matplotlib import pyplot as plt

img_rgb = cv2.imread('mario.jpg')
img_gray = cv2.cvtColor(img_rgb,cv2.COLOR_BGR2GRAY)

template = cv2.imread('mario_coin.png',0)

w,h = template.shape(::-1)

res = cv2.matchTempate(img_gray,template,cv.TM_CCOEFF_NORMED)
thresh = 0.8

loc = np.where(res>= threshold)

for pt in zip(*loc[::-1])
	cv2.rectangle(img_rgb,pt,(pt[0]+w,pt[1]+h),(0,0,255),2)

cv2imwrite('res.png',img_rgb)
