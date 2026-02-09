#include <unistd.h>
#include "../include/cpb/cpb.h"

int main() {
    cpb_init();

    cpb_bar_t* bar = cpb_bar_create(100);
    cpb_bar_set_label(bar, "Downloading");
    cpb_bar_set_width(bar, 40);

    for (int i = 0; i <= 100; i++) {
        cpb_bar_set(bar, i);
        cpb_render();
        usleep(50000);
    }

    cpb_shutdown();
    return 0;
}

