#include <stdio.h>
#include "../../include/cpb/renderer.h"
#include "../../include/cpb/bar.h"
#include "../../include/cpb/terminal.h"

#define MAX_BARS 32

static cpb_bar_t* bars[MAX_BARS];
static int bar_count = 0;

void cpb_renderer_register_bar(void* bar) {
    if (bar_count < MAX_BARS) {
        bars[bar_count++] = (cpb_bar_t*)bar;
    }
}

void cpb_renderer_render_all(void) {
    cpb_terminal_move_cursor_home();

    for (int i = 0; i < bar_count; i++) {
        cpb_bar_render(bars[i]);
    }
    fflush(stdout);
}

void cpb_renderer_clear(void) {
    bar_count = 0;
}

