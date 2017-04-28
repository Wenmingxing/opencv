'''
Coded by luke on 28th April 2017 aiming to test the template matching function in opencv python
'''

import numpy as np
import cv2

from matplotlib import pyplot as plt

img = cv2.imrad('messi.jpg',0)
img2 = img.copy()

template = cv2.imread('template.jpg',0)
w,h = template.shape[::-1]

#all the 6 methods for comparsion in a list
method = ['cv2.TM_CCOFF','cv2.TM_CCOEFF_NORMED','cv2.TM_CCORR','cv2.TM_CCORR_NORMED','cv2.TM_SQDIFF','cv2.TM_SQDIFF_NORMED']

for meth in method:
	img = img2.copy()
	method = eval(meth)

	#apply template matching
	res = cv2.matchTemplate(img,template,method)
	min_val,max_val,min_loc,max_loc = cv2.minMaxLoc(res)

	# if the method is TM_SQDIFF or TM_SQDIFF_NORMED take the minimum
	if method in [cv2.TM_SQDIFF,cv2.TMSQDIFF_NORMED]:
		top_left = min_loc
	
	else:
		top_left = max_loc

	bottom_right = (top_left[0] + w,top_left[1]+h)

	cv2.rectangle(img,top_left,bottom_right,255,2)

	plt.subplot(121),plt.imshow(res,'gray')
	plt.title('matching result'),plt.xticks([]),plt.yticks([])
	
	plt.subplot(122),plt.imshow(img,'gray')
	plt.title('detected points'),plt.xticks([]),plt.yticks([])

	plt.subtitle(meth)

	plt.show()
