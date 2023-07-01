#include "show_odom_node.h"

// ����һ����Ϣ��̨������
// �˺������յ�һ���������õ���Ϊsensor_msgs�Ļ���ʱ�򱻵��á� 
// �������Ϣ�Ǵ�sensor_msgs���ܰ�����Odometry��Ϣ��

void chatterCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
   ROS_INFO("geometry_msgs/PoseWithCovariance pose");
   ROS_INFO("float64 x :%2lf",msg->pose.pose.position.x);
   ROS_INFO("float64 y :%2lf",msg->pose.pose.position.y);
   ROS_INFO("float64 z :%2lf",msg->pose.pose.position.z);
   ROS_INFO("**********************************");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "show_odom_node");  //��ʼ��"show_imu_node"����ڵ�
  ros::NodeHandle n;  // ��������ROSϵͳ��ͨ�ŵĽڵ���
  // ���������ߣ�����һ��������sub��
  // ������sensor_msgs���ܰ��ĵ�Odometry��Ϣ�ļ���
  // ����������"/odom"�������߶���(queue)�Ĵ�С��Ϊ1000��
  ros::Subscriber sub = n.subscribe("/odom", 1000, chatterCallback);
  // ���ڵ��ú�̨�������ȴ�������Ϣ���ڽ��յ���Ϣʱִ�к�̨������
  ros::spin();
  return 0;
}