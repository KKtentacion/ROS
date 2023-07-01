#include "show_imu_node.h"

// 这是一个消息后台函数，
// 此函数在收到一个下面设置的名为sensor_msgs的话题时候被调用。 
// 输入的消息是从sensor_msgs功能包接收Imu消息。

void chatterCallback(const sensor_msgs::Imu::ConstPtr& msg) 
{
   ROS_INFO("geometry_msgs/Quaternion orientation");
   ROS_INFO("float64 x :%2lf",msg->orientation.x);
   ROS_INFO("float64 y :%2lf",msg->orientation.y);
   ROS_INFO("float64 z :%2lf",msg->orientation.z);
   ROS_INFO("float64 w :%2lf",msg->orientation.w);
   ROS_INFO("**********************************");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "show_imu_node");  //初始化"show_imu_node"这个节点
  ros::NodeHandle n;  // 声明用于ROS系统和通信的节点句柄
  // 声明订阅者，创建一个订阅者sub，
  // 它利用sensor_msgs功能包的的imu消息文件。
  // 话题名称是"/imu/data_raw"，订阅者队列(queue)的大小设为1000。
  ros::Subscriber sub = n.subscribe("/imu/data_raw", 1000, chatterCallback); 
  // 用于调用后台函数，等待接收消息。在接收到消息时执行后台函数。
  ros::spin();
  return 0;
}