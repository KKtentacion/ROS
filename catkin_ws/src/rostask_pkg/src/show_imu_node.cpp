#include "show_imu_node.h"

// ����һ����Ϣ��̨������
// �˺������յ�һ���������õ���Ϊsensor_msgs�Ļ���ʱ�򱻵��á� 
// �������Ϣ�Ǵ�sensor_msgs���ܰ�����Imu��Ϣ��

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
  ros::init(argc, argv, "show_imu_node");  //��ʼ��"show_imu_node"����ڵ�
  ros::NodeHandle n;  // ��������ROSϵͳ��ͨ�ŵĽڵ���
  // ���������ߣ�����һ��������sub��
  // ������sensor_msgs���ܰ��ĵ�imu��Ϣ�ļ���
  // ����������"/imu/data_raw"�������߶���(queue)�Ĵ�С��Ϊ1000��
  ros::Subscriber sub = n.subscribe("/imu/data_raw", 1000, chatterCallback); 
  // ���ڵ��ú�̨�������ȴ�������Ϣ���ڽ��յ���Ϣʱִ�к�̨������
  ros::spin();
  return 0;
}