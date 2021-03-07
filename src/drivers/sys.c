#include "sys.h"


// implementation of outportb
void outportb(unsigned short port, unsigned char data) 
{
   // inline assembly
   // out data, port
   // __asm__("operation primary reg, secondary reg" : the return or output : the data taken in or input)
   __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

// implementation of outportb
void outportw(unsigned short port, unsigned short data) 
{
   // inline assembly
   // out data, port
   // __asm__("operation primary reg, secondary reg" : the return or output : the data taken in or input)
   __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

// returns data from a specifide port and takes in the port
unsigned char inportb(unsigned short port)
{
    unsigned char result;
    // inline assembly
    // in port, data
    // __asm__("operation primary reg, secondary reg" : the return or output : the data taken in or input)
    __asm__("in %%dx, %%al" : "=a" (result): "d" (port));

    return result;
}

// returns data from a specifide port and takes in the port
unsigned short inportw(unsigned short port)
{
    unsigned short result;
    // inline assembly
    // in port, data
    // __asm__("operation primary reg, secondary reg" : the return or output : the data taken in or input)
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));

    return result;
}

