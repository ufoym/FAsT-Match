from ctypes import *
import os
import cv2
os.environ['PATH'] = os.path.dirname(__file__) + ';' + os.environ['PATH']
api = CDLL('FAsT.dll')


def match(template_img, test_img):
    tmpl_arr = template_img.ctypes.data_as(POINTER(c_ubyte))
    test_arr = test_img.ctypes.data_as(POINTER(c_ubyte))

    tmpl_h, tmpl_w = template_img.shape[:2]
    test_h, test_w = test_img.shape[:2]

    corners = (c_float * 8)(*([0] * 8))

    score = api.match(tmpl_arr, tmpl_w, tmpl_h,
                      test_arr, test_w, test_h, corners)

    return score, corners

test_img = cv2.imread('image.png', 0)
template_img = cv2.imread('template.png', 0)
print match(template_img, test_img)
