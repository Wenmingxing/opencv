'''
Coded by luke on 28th April 2017 aiming to know more functions for contours in opencv python

'''

# convexity defects
import cv2
import numpy as np

img = cv2.imread('star.jpg')
img_gary = cv2.cvtColor(img,cv2.COLOR_BRG2GRAY)
ret,thresh = cv2.threshold(img_gray,127,255,0)

contours,hierarchy = cv2.findContours(thresh,2,1)

cnt = contours[0]

hull = cv2.convexHull(cnt,returnPoints=False)
defects = cv2.convexityDefect(cnt,hull)

for i in xrange(defect.shape[0]):
	s,e,f,d = defects[i,0]
	start = tuple(cnt[s][0])
	end = tuple(cnt[e][0])
	far = tuple(cnt[f][0])
	cv2.line(img,start,end,[0,255,0],2)
	cv2.circle(img,far,5,[0,0,255],-1)
cv2.imshow('img',img)
cv2.waitkey(0)
cv2.destroyAllWindows()

# point polygon test
dist = cv2.pointPolygonTest(cnt,(50,50),True)


