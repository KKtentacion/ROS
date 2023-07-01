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
  ros::init(argc, argv, "show_depth_camera_node");//初始化"show_depth_camera_node"这个节点
  ros::NodeHandle n;  // 声明用于ROS系统和通信的节点句柄
  image_transport::ImageTransport it(n);
  // 声明订阅者，创建一个订阅者image_sub，
  // 它利用sensor_msgs功能包的的ImageConstPtr&消息文件。
  // 话题名称是"/camera/depth/image_rest_raw"，订阅者队列(queue)的大小设为1000。
  image_transport::Subscriber image_sub_ = it.subscribe("/camera/depth/image_rect_raw", 1000,imageCb);
  // 用于调用后台函数，等待接收消息。在接收到消息时执行后台函数。
  ros::spin();
  return 0;
}