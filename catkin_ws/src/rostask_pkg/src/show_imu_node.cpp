#include "show_imu_node.h"

void chatterCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
  // ROS_INFO("IMU DATA:");
  // ROS_INFO("float64 x :%2lf",msg->orientation.x);
  // ROS_INFO("float64 y :%2lf",msg->orientation.y);
  // ROS_INFO("float64 z :%2lf",msg->orientation.z);
  // ROS_INFO("float64 w :%2lf",msg->orientation.w);
  // ROS_INFO("**********************************");
  std::cout<<"Hello World"<<std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "show_imu_node");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/imu/data_raw", 1000, chatterCallback);
  ros::spin();
  return 0;
}
