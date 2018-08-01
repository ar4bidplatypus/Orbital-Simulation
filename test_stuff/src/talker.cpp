#include "ros/ros.h"
#include "std_msgs/UIint16.h"

#include <sstream>

int main(int argc, char **argv) {

	ros::init(argc, argv, "talker");
	ros::NodeHanle n;

	ros::Publisher sabertooth_pub = n.advertise<std_msgs::UInt16>("sabertoothTopic", 1000);

	ros::Rate loop_rate(10);

	int out = 0;
	while (ros::ok())
	{
		std_msgs::UInt16 address = 128;
		std_msgs::UInt16 command = 7;
		std_msgs::UInt16 data = 64;

		sabertooth_pub.publish(address, command, data);

		ros::spinOnce();

		loop_rate.sleep();
		++count;
	}
	return(0);
}

