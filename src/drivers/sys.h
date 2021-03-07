#pragma once

// return nothing and take in port and data
void outportb(unsigned short port, unsigned char data);

// return nothing and take in port and data
void outportw(unsigned short port, unsigned short data);

// returns data from a specifide port and takes in the port
unsigned char inportb(unsigned short port);

// returns data from a specifide port and takes in the port
unsigned short inportw(unsigned short port);