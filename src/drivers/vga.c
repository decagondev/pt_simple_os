#include "vga.h"
#include "sys.h"

// private method Declerations
int get_cursor_offset();
void set_cursor_offset(int offset);
int print_char(char c, int col, int row, char color);
int get_offset(int col, int row);
int get_offset_col(int offset);
int get_offset_row(int offset);

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
void kprint_at_pos(char *message, int col, int row, char color)
{
    int offset;

    // check if col and row are not negative
    if (col >= 0 && row >= 0)
    {
        offset = get_offset(col, row);
    }
    else
    {
        offset = get_cursor_offset();
        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }

    // loop over all chars in the message
    // set a zero index
    int i = 0;

    // while the message at i is not zero
    while (message[i] != 0)
    {
        offset = print_char(message[i++], col, row, color);

        row = get_offset_row(offset);
        col = get_offset_col(offset);
    }

}
// print a message (kprint())
void kprint(char *message, char color)
{
    kprint_at_pos(message, -1, -1, color);
}

// private helper functions

// print a single char to the screen buffer
int print_char(char c, int col, int row, char color)
{
    // make a ref to the video ram
    unsigned char *screen_buffer = (unsigned char *) VGA_ADDRESS;

    // check if a color was passed in
    if (!color) 
    {
        color = WHITE_ON_BLACK;
    }

    // check if coords are in range
    if (col >= MAX_COLS || row >= MAX_ROWS)
    {
        return get_offset(col, row);
    }

    int offset;

    if (col >= 0 && row >= 0)
    {
        offset = get_offset(col, row);
    }
    else
    {
        offset = get_cursor_offset();
    }


    // newline character
    if (c == '\n')
    {
        row = get_offset_row(offset);
        offset = get_offset(0, row + 1);
    }
    else // to print other chars
    {
        screen_buffer[offset] = c;
        screen_buffer[offset + 1] = color;
        offset += 2;
    }

    set_cursor_offset(offset);
    return offset;
}

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
