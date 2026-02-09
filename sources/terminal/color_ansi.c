#include <stdio.h>
#include "../../include/cpb/color.h"

static int color_enabled = 1;

void cpb_color_enable(int enabled) {
    color_enabled = enabled;
}

void cpb_color_set(cpb_color_t color) {
    if (!color_enabled) return;

    switch (color) {
        case CPB_COLOR_RED:     printf("\033[31m"); break;
        case CPB_COLOR_GREEN:   printf("\033[32m"); break;
        case CPB_COLOR_YELLOW:  printf("\033[33m"); break;
        case CPB_COLOR_BLUE:    printf("\033[34m"); break;
        case CPB_COLOR_MAGENTA: printf("\033[35m"); break;
        case CPB_COLOR_CYAN:    printf("\033[36m"); break;
        case CPB_COLOR_WHITE:   printf("\033[37m"); break;
        default:                printf("\033[0m");  break;
    }
}

void cpb_color_reset(void) {
    if (!color_enabled) return;
    printf("\033[0m");
}
