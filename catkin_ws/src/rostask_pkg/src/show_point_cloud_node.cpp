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