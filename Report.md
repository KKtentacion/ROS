# 软件设计最终项目报告

**writtern by 周飞翔**

这次最终项目最终实现了前三个功能，第四个功能不完善

所有功能的基本思路都是先运用 `rostopic show 对应的topic信息 ` 得出对应的`msg`类型，再根据`rostopic info 对应的topic信息`得出`topic`下的`msg`的格式 ，最后在代码中实现对应的功能

## 第一个功能：

```
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
```

## 第二个功能：

``` 
#include "show_odom_node.h"

// 这是一个消息后台函数，
// 此函数在收到一个下面设置的名为sensor_msgs的话题时候被调用。 
// 输入的消息是从sensor_msgs功能包接收Odometry消息。

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
  ros::init(argc, argv, "show_odom_node");  //初始化"show_imu_node"这个节点
  ros::NodeHandle n;  // 声明用于ROS系统和通信的节点句柄
  // 声明订阅者，创建一个订阅者sub，
  // 它利用sensor_msgs功能包的的Odometry消息文件。
  // 话题名称是"/odom"，订阅者队列(queue)的大小设为1000。
  ros::Subscriber sub = n.subscribe("/odom", 1000, chatterCallback);
  // 用于调用后台函数，等待接收消息。在接收到消息时执行后台函数。
  ros::spin();
  return 0;
}
```

## 第三个功能：

```
#include "show_color_camera_node.h"

void imageCb(const sensor_msgs::ImageConstPtr& msg)
{
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
    cv::imshow("color_camera", cv_ptr->image);
    cv::waitKey(3);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "show_color_camera_node");  //初始化"show_color_camera_node"这个节点
  ros::NodeHandle n;  // 声明用于ROS系统和通信的节点句柄
  image_transport::ImageTransport it(n); 
  // 声明订阅者，创建一个订阅者image_sub，
  // 它利用sensor_msgs功能包的的ImageConstPtr&消息文件。
  // 话题名称是"/camera/color/image_raw"，订阅者队列(queue)的大小设为1000。
  image_transport::Subscriber image_sub_ = it.subscribe("/camera/color/image_raw", 1000,imageCb);
  // 用于调用后台函数，等待接收消息。在接收到消息时执行后台函数。
  ros::spin();
  return 0;
}

```

需要注意的是,在这里我们需要使用到opencv库，因此我们需要在ros系统下执行

```sudo apt-get update
sudo apt-get install libopencv-dev
```

后编译上述代码

## 第四个功能：

``` 
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
  ros::init(argc, argv, "show_depth_camera_node");  //初始化"show_depth_camera_node"这个节点
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
```

类似于第三个功能，就不再过多赘述了

## 第五个功能：

``` 
#include "show_point_cloud_node.h"

pcl::visualization::CloudViewer viewer ("SimPle Cloud Viewer");

void pointcloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg) {
    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::PCLPointCloud2 pcl_pc;
    pcl_conversions::toPCL(*msg, pcl_pc);
    pcl::fromPCLPointCloud2(pcl_pc, cloud);
    viewer.showCloud(cloud.makeShared());
}

int main(int argc ,char **argv){
    ros::init(argc, argv, "show_point_cloud_node");  //初始化"show_point_cloud_node"这个节点
    ros::NodeHandle n;  // 声明用于ROS系统和通信的节点句柄
    // 声明订阅者，创建一个订阅者sub，
    // 它利用sensor_msgs功能包的的PointCloud2消息文件。
    // 话题名称是"/rslidar_points"，订阅者队列(queue)的大小设为1000。
    ros::Subscriber sub = n.subscribe("/rslidar_points", 1000, pointcloudCallback);
    // 用于调用后台函数，等待接收消息。在接收到消息时执行后台函数。
    ros::spin();
    return 0;
}
```

同样的，我们在这一功能中用到了pcl库，因此我们也需要在ros系统下安装我们所需要的库

``` 
sudo apt-get install libpcl-dev
```

在编译上述代码中可能会遇到一些关于`pcl::visualization::CloudViewer viewer ("SimPle Cloud Viewer");`这一行代码的报错，在经过筛查后发现是因为缺少`\#include <pcl/visualization/pcl_visualizer.h>`这一头文件，因此需要将其加入到show_point_node.h这一文件中，并在CmakeList.txt中添加相关编译条件

这就是所有的功能及介绍，感谢阅读!