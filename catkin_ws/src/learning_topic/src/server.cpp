#include <iostream>
#include "learning_topic/AddTwoInts.h"
#include "ros/ros.h"

//service 回调函数，输入参数req，输出参数res
bool add(learning_topic::AddTwoInts::Request &req,learning_topic::AddTwoInts::Response &res)
{
    res.sum = req.a + req.b;
    ROS_INFO("request:x=%ld,y=%ld",(long int)req.a, (long int)req.b);
    ROS_INFO("sending back response：【%ld】", (long int)res.sum);
    
    return true;
}

int main(int argc ,char **argv)
{
    //ROS节点初始化
    ros::init(argc ,argv ,"add_two_ints_service");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个名为add_two_ints的server，注册回调函数add()
    ros::ServiceServer service=n.advertiseService("add_two_ints",add);

    //循环等待回调函数
    ROS_INFO("ready to add two ints:");
    ros::spin();

    return 0;
}