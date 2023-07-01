#include "show_depth_camera_node.h"

void imageCb(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_16UC1);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    cv::imshow("depth_camera", cv_ptr->image);
    cv::waitKey(3);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "show_depth_camera_node");//��ʼ��"show_depth_camera_node"����ڵ�
  ros::NodeHandle n;  // ��������ROSϵͳ��ͨ�ŵĽڵ���
  image_transport::ImageTransport it(n);
  // ���������ߣ�����һ��������image_sub��
  // ������sensor_msgs���ܰ��ĵ�ImageConstPtr&��Ϣ�ļ���
  // ����������"/camera/depth/image_rest_raw"�������߶���(queue)�Ĵ�С��Ϊ1000��
  image_transport::Subscriber image_sub_ = it.subscribe("/camera/depth/image_rect_raw", 1000,imageCb);
  // ���ڵ��ú�̨�������ȴ�������Ϣ���ڽ��յ���Ϣʱִ�к�̨������
  ros::spin();
  return 0;
}