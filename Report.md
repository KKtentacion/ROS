# 软件设计最终项目报告

**writtern by 周飞翔**

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

### 关键步骤：

1. 引入名为`show_imu_node.h`的头文件和其他必要的库。
2. 定义了一个名为`chatterCallback`的回调函数。当接收到名为`/imu/data_raw`的话题的消息时，该函数被调用。
3. 在回调函数中，使用`ROS_INFO`函数打印出IMU消息的四元数方向信息。分别打印出*x*、*y*、*z*和*w*四个方向的值。
4. 主函数中，调用`ros::init`函数进行ROS节点的初始化，将节点名设置为`show_imu_node`。
5. 创建一个`ros::NodeHandle`对象`n`，用于与ROS系统进行通信。
6. 声明一个订阅者`ros::Subscriber`对象`sub`，订阅名为`/imu/data_raw`的话题，设置订阅者队列大小为1000，并将回调函数`chatterCallback`与该订阅者关联。
7. 调用`ros::spin`函数，程序进入消息循环，等待接收消息并执行相应的回调函数。

### 结果：
该程序将接收到的IMU消息中的四元数方向信息打印到终端窗口中，以便查看和分析。

### 算法：
该程序的主要算法是基于ROS框架的消息订阅和回调机制。它通过创建一个订阅者对象，指定订阅的话题和回调函数，来接收IMU消息。当接收到IMU消息时，回调函数被调用，将四元数方向信息打印到终端窗口中。

通过使用ROS的发布-订阅模型，该程序实现了与其他节点之间的通信，实时接收并处理IMU数据。

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

### 关键步骤：

1. 引入名为`show_odom_node.h`的头文件和其他必要的库。
2. 定义了一个名为`chatterCallback`的回调函数。当接收到名为`/odom`的话题的消息时，该函数被调用。
3. 在回调函数中，使用`ROS_INFO`函数打印出`Odometry`消息中的位姿信息。打印出位置的*x*、*y*、*z*三个分量的值。
4. 主函数中，调用`ros::init`函数进行ROS节点的初始化，将节点名设置为`show_odom_node`。
5. 创建一个`ros::NodeHandle`对象`n`，用于与ROS系统进行通信。
6. 声明一个订阅者`ros::Subscriber`对象`sub`，订阅名为`/odom`的话题，设置订阅者队列大小为1000，并将回调函数`chatterCallback`与该订阅者关联。
7. 调用`ros::spin`函数，程序进入消息循环，等待接收消息并执行相应的回调函数。

### 结果：
该程序将接收到的Odometry消息中的位姿信息打印到终端窗口中，以便查看和分析。

### 算法：
该程序的算法主要涉及ROS框架的消息订阅和回调机制。它通过创建一个订阅者对象，并指定要订阅的话题和回调函数，来接收Odometry消息。当接收到Odometry消息时，回调函数被调用，将位姿信息打印到终端窗口中。

通过使用ROS的发布-订阅模型，该程序实现了与其他节点之间的通信，实时接收并处理里程计数据。

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

### 关键步骤：

1. 引入名为`show_color_camera_node.h`的头文件和其他必要的库。
2. 定义了一个名为`imageCb`的回调函数。当接收到名为`/camera/color/image_raw`的话题的消息时，该函数被调用。
3. 在回调函数中，将接收到的图像消息转换为OpenCV格式，使用`cv_bridge`库中的函数`toCvCopy`实现转换。
4. 如果转换出现异常，通过`ROS_ERROR`函数输出错误信息并返回。
5. 使用OpenCV的`imshow`函数显示接收到的图像，窗口名称为"color_camera"。
6. 使用OpenCV的`waitKey`函数等待按键输入，等待时间为3毫秒。
7. 主函数中，调用`ros::init`函数进行ROS节点的初始化，将节点名设置为`show_color_camera_node`。
8. 创建一个`ros::NodeHandle`对象`n`，用于与ROS系统进行通信。
9. 创建一个`image_transport::ImageTransport`对象`it`，用于处理图像传输。
10. 声明一个图像订阅者`image_sub_`，订阅名为`/camera/color/image_raw`的话题，设置订阅者队列大小为1000，并将回调函数`imageCb`与该订阅者关联。
11. 调用`ros::spin`函数，程序进入消息循环，等待接收消息并执行相应的回调函数。

### 结果：
该程序将接收到的彩色相机图像显示在名为"color_camera"的窗口中。

### 算法：
该程序的算法主要涉及ROS框架中的图像订阅和回调机制。通过创建一个图像订阅者对象，指定要订阅的话题和回调函数，程序可以接收彩色相机发布的图像消息。当接收到图像消息时，回调函数被调用，将图像转换为OpenCV格式并显示在窗口中。

通过使用ROS的发布-订阅模型和image_transport功能包，该程序实现了与彩色相机节点之间的通信，实时接收和显示图像数据。

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

### 关键步骤：

1. 引入名为`show_depth_camera_node.h`的头文件和其他必要的库。
2. 定义了一个名为`imageCb`的回调函数。当接收到名为`/camera/depth/image_rect_raw`的话题的消息时，该函数被调用。
3. 在回调函数中，将接收到的图像消息转换为OpenCV格式的16位无符号整数类型，使用cv_bridge库中的函数`toCvCopy`实现转换。
4. 如果转换出现异常，通过`ROS_ERROR`函数输出错误信息并返回。
5. 使用OpenCV的`imshow`函数显示接收到的深度图像，窗口名称为"depth_camera"。
6. 使用OpenCV的`waitKey`函数等待按键输入，等待时间为3毫秒。
7. 主函数中，调用`ros::init`函数进行ROS节点的初始化，将节点名设置为`show_depth_camera_node`。
8. 创建一个`ros::NodeHandle`对象`n`，用于与ROS系统进行通信。
9. 创建一个`image_transport::ImageTransport`象`it`，用于处理图像传输。
10. 声明一个图像订阅者`image_sub_`，订阅名为`/camera/depth/image_rect_raw`的话题，设置订阅者队列大小为1000，并将回调函数imageCb与该订阅者关联。
11. 调用`ros::spin`函数，程序进入消息循环，等待接收消息并执行相应的回调函数。

### 结果：
该程序将接收到的深度相机图像显示在名为"depth_camera"的窗口中。

### 算法：
该程序的算法主要涉及ROS框架中的图像订阅和回调机制。通过创建一个图像订阅者对象，指定要订阅的话题和回调函数，程序可以接收深度相机发布的深度图像消息。当接收到图像消息时，回调函数被调用，将图像转换为OpenCV格式并显示在窗口中。

通过使用ROS的发布-订阅模型和image_transport功能包，该程序实现了与深度相机节点之间的通信，实时接收和显示深度图像数据。

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

### 关键步骤：

1. 引入名为`show_depth_camera_node.h`的头文件和其他必要的库。
2. 定义了一个名为`imageCb`的回调函数。当接收到名为`/camera/depth/image_rect_raw`的话题的消息时，该函数被调用。
3. 在回调函数中，将接收到的图像消息转换为OpenCV格式的16位无符号整数类型，使用`cv_bridge`库中的函数`toCvCopy`实现转换。
4. 如果转换出现异常，通过`ROS_ERROR`函数输出错误信息并返回。
5. 使用OpenCV的`imshow`函数显示接收到的深度图像，窗口名称为`depth_camera`。
6. 使用OpenCV的`waitKey`函数等待按键输入，等待时间为3毫秒。
7. 主函数中，调用`ros::init`函数进行ROS节点的初始化，将节点名设置为`show_depth_camera_node`。
8. 创建一个`ros::NodeHandle`对象`n`，用于与ROS系统进行通信。
9. 创建一个`image_transport::ImageTransport`对象`it`，用于处理图像传输。
10. 声明一个图像订阅者`image_sub_`，订阅名为`/camera/depth/image_rect_raw`的话题，设置订阅者队列大小为1000，并将回调函数`imageCb`与该订阅者关联。
11. 调用`ros::spin`函数，程序进入消息循环，等待接收消息并执行相应的回调函数。

### 结果：
该程序将接收到的深度相机图像显示在名为"depth_camera"的窗口中。

### 算法：
该程序的算法主要涉及ROS框架中的图像订阅和回调机制。通过创建一个图像订阅者对象，指定要订阅的话题和回调函数，程序可以接收深度相机发布的深度图像消息。当接收到图像消息时，回调函数被调用，将图像转换为OpenCV格式并显示在窗口中。

通过使用ROS的发布-订阅模型和image_transport功能包，该程序实现了与深度相机节点之间的通信，实时接收和显示深度图像数据。



同样的，我们在这一功能中用到了pcl库，因此我们也需要在ros系统下安装我们所需要的库

``` 
sudo apt-get install libpcl-dev
```

在编译上述代码中可能会遇到一些关于`pcl::visualization::CloudViewer viewer ("SimPle Cloud Viewer");`这一行代码的报错，在经过筛查后发现是因为缺少`\#include <pcl/visualization/pcl_visualizer.h>`这一头文件，因此需要将其加入到show_point_node.h这一文件中，并在CmakeList.txt中添加相关编译条件

## 第六个功能：

```
#include "show_map_node.h"


void callback(const nav_msgs::OccupancyGrid::ConstPtr& ptr)
{   
    std::cout << "resolution: " << ptr->info.resolution << std::endl;
    std::cout << "width: " << ptr->info.width << std::endl;
    std::cout << "height: " << ptr->info.height << std::endl;
    double scale = 1.0;
    int width = 1200;
    int height = 1200;
    cv::Point offset = {-1600, -1600};
    cv::Mat map = cv::Mat::zeros(cv::Size(width, height), CV_8UC3);
    for (int i = 0; i < ptr->info.width * ptr->info.height; ++i) {
        int x = (i % ptr->info.width + offset.x) * scale, y = (i / ptr->info.width + offset.y) * scale;
        if (ptr->data[i] == -1) {
            cv::circle(map, cv::Point(x, y), 1, cv::Scalar(255, 255, 255), -1);
        } else if (ptr->data[i] >= 80) {
            cv::circle(map, cv::Point(x, y), 3, cv::Scalar(0, 0, 0), -1);
        } else {
            cv::circle(map, cv::Point(x, y), 3, cv::Scalar(0, 255, 0), -1);
        }    
    }
    cv::imshow("map", map);
    cv::waitKey(1000);
    return ;
}

void LaunchGMapping()
{
    system("rosrun gmapping slam_gmapping");
}

int main(int argc, char** argv)
{
    std::thread gm(LaunchGMapping);  
    ros::init(argc, argv, "show_map_node");  
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/map", 1000, callback);
    ros::spin();
    return 0;
}
```

该程序是一个使用ROS框架的C++程序。它订阅了名为"/map"的话题，并使用OpenCV库来可视化接收到的占用网格地图。

### 关键步骤：

1. 引入所需的头文件"show_map_node.h"和其他必要的库。
2. 定义了一个名为`callback`的回调函数。在这个函数中，程序通过指针ptr访问接收到的占用网格地图的信息，并将其打印出来。
3. 创建了一个`cv::Mat`类型的图像对象`map`，用于存储地图的可视化结果。
4. 使用循环遍历占用网格地图的每个元素。根据元素的值，选择不同的颜色和形状来绘制地图中的点。
5. 最后，使用OpenCV的`imshow`函数将可视化结果显示在名为"**map**"的窗口中，并使用`waitKey`函数等待1秒钟。

### 结果：
该程序将占用网格地图可视化为一个图像，并在一个窗口中显示出来。地图中的不同颜色和形状的点代表了不同的地图状态。具体来说，白色的点表示未知区域，黑色的点表示占用区域，绿色的点表示自由区域。

### 算法：
该程序主要是一个数据处理和图像绘制的slam算法。它通过遍历占用网格地图的每个元素，并根据元素的值选择不同的颜色和形状来绘制地图中的点。这种可视化方式可以帮助我们更直观地理解地图的结构和内容。

此外，程序还使用了ROS的相关函数和功能，如`ros::init`、`ros::NodeHandle`和`ros::Subscriber`，以实现与ROS系统的通信和数据接收。

这就是所有的功能及介绍，感谢阅读!