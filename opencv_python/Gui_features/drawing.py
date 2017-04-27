'''
Coded by luke  on 27th April 2017 aiming to familiarize the drawing functions provided by python opencv

'''
import numpy as np
import cv2


# create a black image

img = np.zeros((512,512,3),np.uint8)

# Draw a diagnonal blue line with thickness of 5 px
cv2.line(img,(0,0),(511,511),(255,0,0),5)

# Draw the rectangle with top left and bottom right corner
cv2.rectangle(img,(384,0),(510,128),(0,255,0),3)

#Draw the circle with center and radius
cv2.circle(img,(447,63),63,(0,0,255),-1)

#Draw ellipse
cv2.ellipse(img,(256,256),(100,50),0,0,180,255,-1)

# Draw the polygon
pts = np.array([[10,5],[20,30],[70,20],[50,10]],np.int32)
pts = pts.reshape((-1,1,2))
print(pts.shape)
cv2.polylines(img,[pts],True,(0,255,255))

#Adding test to the images
font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img,'OpenCV',(10,500),font,4,(255,255,255),2,cv2.LINE_AA)


cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindow()

 
