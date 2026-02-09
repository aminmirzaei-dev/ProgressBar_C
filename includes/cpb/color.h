#ifndef CPB_COLOR_H
#define CPB_COLOR_H

/* ANSI color codes */
typedef enum {
    CPB_COLOR_DEFAULT = 0,
    CPB_COLOR_RED,
    CPB_COLOR_GREEN,
    CPB_COLOR_YELLOW,
    CPB_COLOR_BLUE,
    CPB_COLOR_MAGENTA,
    CPB_COLOR_CYAN,
    CPB_COLOR_WHITE
} cpb_color_t;

/* Enable / disable color output */
void cpb_color_enable(int enabled);

/* Set foreground color */
void cpb_color_set(cpb_color_t color);

/* Reset color to default */
void cpb_color_reset(void);

#endif /* CPB_COLOR_H */

