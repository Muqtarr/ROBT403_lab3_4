#include "ros/ros.h" 
#include "std_msgs/Float64.h"


#include <math.h>

ros::Publisher pub3;
float previousValue = 0.0;


void valueCallback(const std_msgs::Float64::ConstPtr& msg) { 
     
    float newValue = msg->data; 

    if (newValue > previousValue) { 
         
	pub3.publish(msg);
	previousValue = newValue;
	ROS_INFO("Sending command to move to: %f", newValue);
	
    } else { 
        ROS_INFO("No movement needed."); 
    } 
}


int main(int argc, char **argv){

 ros::init(argc,argv, "rotate");
 ros::NodeHandle nh;
 ros::NodeHandle n1;

 pub3 = nh.advertise<std_msgs::Float64>("/joint4/command", 100);
 ros::Subscriber sub = n1.subscribe("chatter", 1000, valueCallback);
 ros::Rate loop_rate (10);
 ros::Time startTime = ros::Time::now();

     while (ros::ok()) { 
 	
 	ros::spinOnce();
 	loop_rate.sleep();
    }
}



