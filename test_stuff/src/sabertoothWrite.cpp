#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include "std_msgs/String.h"
#include "serialWriter.h"
#include "test_stuff/sabertooth.h"

using namespace std;

serialWriter writer;

void callBack(const test_stuff::sabertooth msg) {
	ROS_INFO("Address: [%d], command: [%d], data: [%d]\n", msg.address, msg.command, msg.data);
	uint16_t address = msg.address;
	uint16_t command = msg.command;
	uint16_t data = msg.data;
	writer.serialWrite(address, command, data);
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "sabertoothWriteNode");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("sabertoothTopic", 1000, callBack);
	ros::spin();

}//main
