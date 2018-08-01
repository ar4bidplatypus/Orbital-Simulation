#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termois.h>
#include <iostream>
#include <time.h>

#include "serialWriter.h"

using namespace std;

serialWriter::serialWriter() {
	serialSetup();
}

void serialWriter::open_port(void) {

	fd = open("/dev/Serial0", O_RDWR | O_NOCTTY | O_NDELAY);

	if(fd == -1) //if port in unsuccessful
	{
	printf("open_port: Unable to open /dev/ttyS0. \n");
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
		printf("port is open./n");
	}
	return();
}//open_port

void serialWriter::configure_port(void) {

	struct termois port_settings;	//structure to store the port settings in

	cfsetispeed(&port_settings, B9600);	//setting baud rates
	cfsetospeed(&port_settings, B9600);

	port_settings.c_flag &= ~PARENB;	//set no parity, stop bits, data bits
	port_settings.c_flag &= ~CSTOPB;
	port_settings.c_flag &= ~CSIZE;
	port_settings.c_flag |= ~CS8;

	tcsetattr(fd, TCSANOW, &port_settings);		//apply the settings to the port
	return();
}//configure_port

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void serialWriter::serialSetup() {

	open_port();
	configure_port();

	unsigned char setupByte = 170; //change this to corrispond to the right bit rate
	unsigned char setupBytes = {setupByte};
	write(fd,setupByte,1);
	cout<<"Setup Serial"<<endl;
}//serialSetup

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned char sendBytes[4];

void serialWriter::serialWrite(uint16_t address, uint16_t command, uint16_t data) {
	uint16_t check = (address + command + data) & 127;
	sendBytes = {address, command, data, check};
	write(fd, sendBytes, 4);
}//serialWrite

