#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/cpb/bar.h"
#include "../../include/cpb/renderer.h"

/* Progress bar internal structure */
struct cpb_bar {
    int value;
    int max;
    int width;
    char label[64];
};

/* Create a new progress bar */
cpb_bar_t* cpb_bar_create(int max) {
    cpb_bar_t* bar = malloc(sizeof(cpb_bar_t));
    if (!bar) return NULL;

    bar->value = 0;
    bar->max = max;
    bar->width = 30;
    strcpy(bar->label, "Progress");

    cpb_renderer_register_bar(bar);
    return bar;
}

void cpb_bar_set_label(cpb_bar_t* bar, const char* label) {
    strncpy(bar->label, label, sizeof(bar->label) - 1);
}

void cpb_bar_set_width(cpb_bar_t* bar, int width) {
    bar->width = width;
}

void cpb_bar_set(cpb_bar_t* bar, int value) {
    if (value > bar->max) value = bar->max;
    bar->value = value;
}

void cpb_bar_increment(cpb_bar_t* bar, int delta) {
    cpb_bar_set(bar, bar->value + delta);
}

int cpb_bar_is_finished(cpb_bar_t* bar) {
    return bar->value >= bar->max;
}

void cpb_bar_render(const cpb_bar_t* bar) {
    int filled = (bar->value * bar->width) / bar->max;

    printf("%s [", bar->label);
    for (int i = 0; i < bar->width; i++) {
        printf(i < filled ? "#" : " ");
    }
    printf("] %3d%%\n", (bar->value * 100) / bar->max);
}

void cpb_bar_destroy(cpb_bar_t* bar) {
    free(bar);
}

