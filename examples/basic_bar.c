#include <unistd.h>     // usleep
#include <stdio.h>

#include "../include/cpb/cpb.h"
#include "../include/cpb/bar.h"
#include "../include/cpb/color.h"

/*
 * Example program demonstrating usage of CPB
 * Console Progress Bar Library
 */
int main(void) {

    /* Initialize CPB library and terminal state */
    cpb_init();

    /* Enable colored output (can be disabled if needed) */
    cpb_color_enable(1);

    /* Create a progress bar with max value = 100 */
    cpb_bar_t* bar = cpb_bar_create(100);
    if (!bar) {
        fprintf(stderr, "Failed to create progress bar\n");
        cpb_shutdown();
        return 1;
    }

    /* Configure bar appearance */
    cpb_bar_set_label(bar, "Downloading");
    cpb_bar_set_width(bar, 40);

    cpb_bar_set_fill_color(bar, CPB_COLOR_GREEN);
    cpb_bar_set_empty_color(bar, CPB_COLOR_WHITE);
    cpb_bar_set_label_color(bar, CPB_COLOR_CYAN);

    /* Simulate progress */
    for (int i = 0; i <= 100; i++) {
        cpb_bar_set(bar, i);

        /* Render all registered progress bars */
        cpb_render();

        /* Artificial delay for demonstration */
        usleep(50000); /* 50 ms */
    }

    /* Cleanup and restore terminal */
    cpb_bar_destroy(bar);
    cpb_shutdown();

    printf("\nDone!\n");
    return 0;
}
