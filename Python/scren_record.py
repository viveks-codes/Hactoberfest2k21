import cv2
import numpy as np
import pyautogui
screen_size = (1920,1080)
fourcc = cv2.videowriter(*"XVID")
out = cv2.videowriter("output.avi",fourcc,20.0,(screen_size))
while True:
    img = pyautogui.screenshot()
    frame = np.array(img)
    frame = cv2.cvtcolor(frame,cv2.COLORBGR2RBG)
    out.Write(frame)
    #  if user clicks q , it exists
    if cv2.waitkey(1) == ord("q"):
        break
cv2.destroyALLWindows()
out.release()

