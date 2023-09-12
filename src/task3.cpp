#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <math.h>

ros::Publisher joint1_pub;
const double PI = 3.14159265359;

void jointController(ros::Publisher& pub, const std::string& joint_name, double amplitude, double frequency) {
    ros::Rate rate(10);  

    while (ros::ok()) {
        double t = ros::Time::now().toSec();
        double angle = amplitude * sin(2 * PI * frequency * t);

        std_msgs::Float64 msg;
        msg.data = angle;

        pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "joint_step_response");
    ros::NodeHandle nh;

 
    joint1_pub = nh.advertise<std_msgs::Float64>("/end/command", 10);
    std::string joint1_name = "joint1";  
    double joint1_amplitude = 0.5;      
    double joint1_frequency = 0.5;           
    
    jointController(joint1_pub, joint1_name, joint1_amplitude, joint1_frequency);
    
}
