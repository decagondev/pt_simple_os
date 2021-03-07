#include "vga.h"
#include "sys.h"

// VGA Kernel API
// clear the screen (clear_screen())
void clear_screen(unsigned char color)
{
    // a ref to our screen buffer
    char *screen_buffer = VGA_ADDRESS;
    // total size of the screen
    int screen_size = MAX_COLS * MAX_ROWS;


    // iterate over the screen buffer
    for (int i = 0; i < screen_size; i++)
    {
        // put a blank space at index * 2 of the screen buffer
        screen_buffer[i * 2] = ' ';
        // put the color in the next index of the screen buffer
        screen_buffer[i * 2 + 1] = color;
    }
    
    // set the cursor offset
    set_cursor_offset(get_offset(0, 0));
}
// print at position (kprint_at_pos())
void kprint_at_pos(char *message, int col, int row)
{

}
// print a message (kprint())
void kprint(char *message)
{

}

// private helper functions

// get offset (col and row)
int get_offset(int col, int row) 
{
    return 2 * (row * MAX_COLS + col);
}

// get offset (row)
int get_offset_row(int offset) 
{
    return offset / (2 * MAX_COLS);
}

// get offset (col)
int get_offset_col(int offset) 
{
    return (offset - (get_offset_row(offset) * 2 * MAX_COLS)) / 2;
}

// port operations

// get cursor offset 
int get_cursor_offset()
{
    // High byte
    outportb(VGA_CTRL_REG, 14);
    int offset = inportb(VGA_DATA_REG) << 8;
    
    // Low byte
    outportb(VGA_CTRL_REG, 15);
    offset += inportb(VGA_DATA_REG);
  
    return offset * 2;
}

// set cursor offset
void set_cursor_offset(int offset)
{
    offset /= 2;

    // High byte
    outportb(VGA_CTRL_REG, 14);
    outportb(VGA_DATA_REG, (unsigned char)(offset >> 8));
    
    // Low byte
    outportb(VGA_CTRL_REG, 15);
    outportb(VGA_DATA_REG, (unsigned char)(offset & 0xff));
}
