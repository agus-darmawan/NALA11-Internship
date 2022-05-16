from multiprocessing.connection import wait
import rospy
import cv2 
import numpy as np
from materi_3.msg import value


def callback (value):
    rospy.loginfo("MAXHSV : %d %d %d",value.maxh, value.maxs, value.maxv)
    rospy.loginfo("MINHSV : %d %d %d",value.minh, value.mins, value.minv)
    mask_color(value.maxh, value.maxs, value.maxv, value.minh, value.mins, value.minv)

def listener():
    rospy.init_node("Subscriber_Node",anonymous = True)
    rospy.Subscriber('materi_3', value, callback)

def mask_color(a, b, c, d, e, f ):
    cap = cv2.VideoCapture(0)
    while 1:
        _,frame =cap.read()
        into_hsv =cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
        L_limit=np.array([a,b,c])
        U_limit=np.array([d,e,f]) 
            

        b_mask=cv2.inRange(into_hsv,L_limit,U_limit)
        blue=cv2.bitwise_and(frame,frame,mask=b_mask)
        contours, hierarchy = cv2.findContours(b_mask,
                                           cv2.RETR_TREE,
                                           cv2.CHAIN_APPROX_SIMPLE)
        for pic, contour in enumerate(contours):
            area = cv2.contourArea(contour)
            if(area>200):
                x, y, w, h = cv2.boundingRect(contour)
                frame = cv2.rectangle(frame, (x, y), 
                                            (x + w, y + h), 
                                            (0, 0, 255), 2)
                    
                cv2.putText(frame, "Colour", (x, y),
                            cv2.FONT_HERSHEY_SIMPLEX, 1.0,
                            (0, 0, 255))
        cv2.imshow("Color Detction Frame", frame)
        if cv2.waitKey(10) & 0xFF == ord('q'):
            cap.release()
            cv2.destroyAllWindows()
            break
    cap.release()
    cv2.destroyAllWindows()
if __name__ == '__main__':
  listener()
  rospy.spin()