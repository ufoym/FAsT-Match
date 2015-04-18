import cv2
import FAsT

test_img = cv2.imread('image.png', 0)
template_img = cv2.imread('template.png', 0)
corners = [0] * 8
tmpl_h, tmpl_w = template_img.shape[:2]
test_h, test_w = test_img.shape[:2]
FAsT.match(template_img, test_img)
