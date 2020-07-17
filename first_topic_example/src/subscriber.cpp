#include<ros/ros.h>
#include<first_topic_example/time.h>

void timer(const first_topic_example::time::ConstPtr& msg)
{

	ROS_INFO("Second that receipted : %d ",msg->stamp.sec);
	ROS_INFO("Nano second that receipted : %d",msg->stamp.nsec);
	ROS_INFO("Data that receipted : %d",msg->data);

}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"topic_subscriber");
	ros::NodeHandle nh;

	ros::Subscriber topic_subscriber = nh.subscribe("msg_time",100,timer);
	ros::spin();


return 0;
}
