#include <stdio.h>
#include "../../include/cpb/terminal.h"

void cpb_terminal_clear(void) {
    printf("\033[2J");
}

void cpb_terminal_move_cursor_home(void) {
    printf("\033[H");
}

void cpb_terminal_hide_cursor(void) {
    printf("\033[?25l");
}

void cpb_terminal_show_cursor(void) {
    printf("\033[?25h");
}

