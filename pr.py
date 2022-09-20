import cv2, numpy as np, matplotlib as mp

image = np.zeros((500, 800), np.uint8)
image.fill(200)

cv2.imshow("window title", image)
cv2.waitKey(0)
cv2.destroyAllWindows()