#ifndef CPB_TERMINAL_H
#define CPB_TERMINAL_H

/* Terminal control (ANSI based) */
void cpb_terminal_clear(void);
void cpb_terminal_move_cursor_home(void);
void cpb_terminal_hide_cursor(void);
void cpb_terminal_show_cursor(void);

#endif /* CPB_TERMINAL_H */

