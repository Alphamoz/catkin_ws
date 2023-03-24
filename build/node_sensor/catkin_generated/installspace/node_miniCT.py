#!/usr/bin/env python2
# license removed for brevity
import rospy
from std_msgs.msg import String

def talker():
    pub1 = rospy.Publisher('messageMiniCT', String, queue_size=10)
    rospy.init_node('node_miniCT')
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "depth %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub1.publish(hello_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
