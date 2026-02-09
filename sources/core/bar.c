#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/cpb/bar.h"
#include "../../include/cpb/color.h"
#include "../../include/cpb/renderer.h"

struct cpb_bar {
    int value;
    int max;
    int width;
    char label[64];

    cpb_color_t fill_color;
    cpb_color_t empty_color;
    cpb_color_t label_color;
};

cpb_bar_t* cpb_bar_create(int max) {
    cpb_bar_t* bar = malloc(sizeof(cpb_bar_t));
    if (!bar) return NULL;

    bar->value = 0;
    bar->max = max;
    bar->width = 30;
    strcpy(bar->label, "Progress");

    bar->fill_color  = CPB_COLOR_GREEN;
    bar->empty_color = CPB_COLOR_WHITE;
    bar->label_color = CPB_COLOR_CYAN;

    cpb_renderer_register_bar(bar);
    return bar;
}

void cpb_bar_set_fill_color(cpb_bar_t* bar, cpb_color_t color) {
    bar->fill_color = color;
}

void cpb_bar_set_empty_color(cpb_bar_t* bar, cpb_color_t color) {
    bar->empty_color = color;
}

void cpb_bar_set_label_color(cpb_bar_t* bar, cpb_color_t color) {
    bar->label_color = color;
}

void cpb_bar_render(const cpb_bar_t* bar) {
    int filled = (bar->value * bar->width) / bar->max;

    cpb_color_set(bar->label_color);
    printf("%s ", bar->label);
    cpb_color_reset();

    printf("[");

    for (int i = 0; i < bar->width; i++) {
        if (i < filled) {
            cpb_color_set(bar->fill_color);
            printf("#");
        } else {
            cpb_color_set(bar->empty_color);
            printf(" ");
        }
    }

    cpb_color_reset();
    printf("] %3d%%\n", (bar->value * 100) / bar->max);
}
