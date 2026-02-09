#include "../../include/cpb/cpb.h"
#include "../../include/cpb/renderer.h"
#include "../../include/cpb/terminal.h"

/*
 * Initialize CPB library
 * Clears the terminal and prepares rendering environment
 */
void cpb_init(void) {
    cpb_terminal_clear();
    cpb_terminal_move_cursor_home();
    cpb_terminal_hide_cursor();
}

/*
 * Render all registered UI components
 */
void cpb_render(void) {
    cpb_renderer_render_all();
}

/*
 * Restore terminal state and cleanup resources
 */
void cpb_shutdown(void) {
    cpb_terminal_show_cursor();
    cpb_renderer_clear();
}

