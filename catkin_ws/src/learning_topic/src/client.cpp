#include <cstdlib>
#include "ros/ros.h"
#include "learning_topic/AddTwoInts.h"

int main(int argc ,char **argv)
{
    //初始化ros节点
    ros::init(argc,argv,"add_two_ints_client");

    //从终端获取2个加数
    if (argc != 3)
    {
        ROS_INFO("usage: add_two_ints_client x y");
        return 1;
    }

    //创建节点 句柄
    ros::NodeHandle n;

    //创建一个client，请求add——two_ints_service
    ros::ServiceClient client = n.serviceClient<learning_topic::AddTwoInts>("add_two_ints");

    //创建learning_topic::AddTwoInts类型的Service消息
    learning_topic::AddTwoInts srv;
    srv.request.a = atoll(argv[1]);
    srv.request.b = atoll(argv[2]);

    //发布service请求，等待加法运算的结果
    if(client.call(srv))
    {
        ROS_INFO("sum:%ld",(long int)srv.response.sum);
    }
    else
    {
        ROS_ERROR("fail to call service add_two_ints");
        return 1;
    }

    return 0;
    
    
}