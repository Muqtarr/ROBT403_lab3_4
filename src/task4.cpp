#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>

ros::Publisher joint1_pub;
ros::Publisher joint2_pub;
ros::Publisher joint3_pub;
ros::Publisher joint4_pub;
ros::Publisher joint5_pub;
const double PI = 3.14159265359;

int main(int argc, char **argv) {
    ros::init(argc, argv, "joint_task5");
    
    ros::NodeHandle nh;
    ros::NodeHandle nh1;
    ros::NodeHandle nh2;
    ros::NodeHandle nh3;
    ros::NodeHandle nh4;
 
    double frequency = 0.4;
    double amplitude = 0.5;

    joint1_pub = nh.advertise<std_msgs::Float64>("/motortom2m/command", 10);

    joint2_pub = nh1.advertise<std_msgs::Float64>("/joint2/command", 10);
    
    joint3_pub = nh2.advertise<std_msgs::Float64>("/joint4/command", 10);
   
    joint4_pub = nh3.advertise<std_msgs::Float64>("/joint6/command", 10);

    joint5_pub = nh4.advertise<std_msgs::Float64>("/end/command", 10);
         
    ros::Rate rate(10);
    std_msgs::Float64 msg;

     while (ros::ok()) {
        double t = ros::Time::now().toSec();

        msg.data = (amplitude / 2) * sin(2 * PI * frequency * t);	
        joint1_pub.publish(msg);
	
	msg.data = amplitude * sin(2 * PI * frequency * (t + 1/(2*frequency)));
	joint2_pub.publish(msg);

	msg.data = amplitude * sin(2 * PI * frequency * t);
	joint3_pub.publish(msg);

	msg.data = amplitude * sin(2 * PI * frequency * (t + 1/(2*frequency)));
	joint4_pub.publish(msg);

	msg.data = amplitude * sin(2 * PI * frequency * t);	
	joint5_pub.publish(msg);	

        ros::spinOnce();
        rate.sleep();
    }
    
}
