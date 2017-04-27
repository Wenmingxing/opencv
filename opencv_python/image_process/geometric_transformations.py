'''
Coded by luke on 27th April 2017 aiming to test the geometric transformation functions in opencv

'''

import numpy as np
import cv2

img = cv2.imread('roi.jpg')

res = cv2.resize(img,None,fx = 2,fy = 2,interpolation = cv2.INTER_CUBIC)

#OR

height,width = img.shape[:2]
res = cv2.resize(img,(2*width,2*height),interpolation = cv2.INTER_CUBIC)

img = cv2.imread('roi.jpg',0)

rows,cols = img.shape

m = np.float32([[1,0,100],[0,1,50]])
dst = cv2.warpAffine(img,m,(cols,rows))

cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

img = cv2.imread('roi.jpg',0)
rows,cols = img.shape

m = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst = cv2.warpAffine(img,m,(cols,rows))

#Affine transform
img = cv2.imread('drawing.png')
rows,cols,ch = img.shape

pst1 = np.float32([[50,50],[200,50],[50,200]])
pst2 = np.float32([[10,100],[200,50],[100,250]])

m = cv2.getAffineTranform(pts1,pts2)

dst = cv2.warpAffine(img,m,(cols,rows))

plt.subplot(121),plt.imshow(img),plt.title('input')
plt.subplot(122),plt.imshow(dst),plt.title('output')
plt.show()

#perspective transformation
img = cv2.imread('sudousmall.png')
rows,cols,ch = img.shape

pts1 = np.float32([[56,65],[368,52],[28,387],[389,390]])
pts2 = np.float32([[0,0],[300,0],[0,300],[300,300]])

m = cv2.getPerspectiveTransform(pts1,pts2)

dst = cv2.warpPerspective(img,m,(300,300))

plt.subplot(121),plt.inshow(img),plt.title('input')
plt.subplot(122),plt.imshow(dst),plt.title('output')
plt.show()
