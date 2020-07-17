#include<ros/ros.h>
#include<first_topic_example/time.h>

int main(int argc, char **argv)
{

	ros::init(argc,argv,"publisher");
	ros::NodeHandle nh;

	ros::Publisher topic_publisher = nh.advertise<first_topic_example::time>("msg_time",100);
	ros::Rate loop(10);

	first_topic_example::time msg;
	int count = 0;
	
	while(ros::ok())
	{
		msg.stamp = ros::Time::now();
		msg.data = count;
		ROS_INFO("Time that sent : %d", msg.stamp.sec);
		ROS_INFO("Data that sent : %d", msg.data);
		topic_publisher.publish(msg);		
		loop.sleep();
		++count;
	}

return 0;
}
