# ROS-
利用松灵小车上录制的bag包数据（从QQ群下载），编写软件，展示ROS系统中的各类数据，具体包括：
1. 用命令行窗口显示小车的IMU和里程计（odometry）数据；
2. 用图形界面显示颜色相机和深度相机的数据（利用OpenCV库）；
3. 用图形界面显示激光雷达的点云数据（利用PCL库）；
4. 自行选择一种高级算法（例如语义分割、三维重建、导航定位（SLAM）等），实现该算法（可以直接利用第三方库），将其集成到系统中。

### 代码要求
1. 所有程序代码采用C++编写，使用git进行源代码管理；

2. 类名、变量名、函数名应符合C++的命名规范，并在代码中前后保持一致；

3. 涉及面向对象的程序，例如自定义的类，应符合面向对象的设计原则；

4. 正确使用头文件和源文件，自定义的头文件应符合头文件的编写原则，例如用条件宏定义确保头文件不被多次引用、不在头文件中进行类和函数的实现（模板除外）；

5. 项目必须是ROS项目，符合ROS的项目的规范，正确编写CmakeLists.txt等文件；

   实现效果视频链接：[ros系统展示_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1PX4y1i7jt/)
