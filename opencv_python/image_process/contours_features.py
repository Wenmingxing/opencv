'''
Coded by luke on 27th April 2017 aiming to test the features  for contours

'''

import cv2
import numpy as np

img = cv2.imread('star.jpg',0)
img = cv2.GaussianBlur(img,(5,5),0)
ret,thresh = cv2.threshold(img,127,255,0)

contour,hierarchy = cv2.findContours(thresh,1,2)

cnt = contours[0]

m = cv2.moments(cnt)
print m


cx = int(m['m10']/m['m00'])
cy = int(m['m01']/m['m00'])

area = cv2.contourArea(cnt)

#contour perimeter
perimeter = cv2.arcLength(cnt,True)



#Contours approximation
epsilon = 0.1*cv2.arcLength(cnt,True)
approx = cv2.approxPolyDP(cnt,epsilon,True)

# convex hull function for contours
hull = cv2.convexHull(cnt)

# checking convexity
k = cv2.isContourConvex(cnt)

# Bounding rectangle
x,y,w,h = cv2.boundingRect(cnt)

cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)

#Rotated rectangle,draw the rectangle with mimimun area for the contours
rect = cv2.minAreaRect(cnt)
box = cv2.boxPoints(rect)

box = np.int0(box)
cv2.drawContours(img,[box],0,(0,0,255),2)

# minimum enclosing circle
(x,y),center = cv2.minEnclosingCircle(cnt)
center = (int(x),int(y))
radius = int(radius)
cv2.circle(img,center,radius,(0,255,0),2)

#fitting an ellipse
ellipse = cv2.fitEllipse(cnt)
cv2.ellipse(img,ellipse,(0,255,0),2)

#fitting line

rows,cols = img.shape[:2]

[vx,vy,x,y] = cv2.fitLine(cnt.DIST_L2,0,0.01,0.01)
lefty = int((-x*vy/vx)+y)
righty = int(((cols-x)*vy/vx)+y)

cv2.line(img,(cols-1,righty),(0,lefty),(0,255,0),2)


