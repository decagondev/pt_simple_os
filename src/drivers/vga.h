#pragma once

#define VGA_ADDRESS 0xb8000
#define MAX_COLS 80
#define MAX_ROWS 25

// colors (more to come)
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4
#define WHITE_ON_RED 0x4f


// VGA PORTS
#define VGA_CTRL_REG 0x3d4
#define VGA_DATA_REG 0x3d5

// VGA Kernel API
// clear the screen (clear_screen())
void clear_screen(unsigned char color);
// print at position (kprint_at_pos())
void kprint_at_pos(char *message, int col, int row);
// print a message (kprint())
void kprint(char *message);

