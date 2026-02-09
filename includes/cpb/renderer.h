#ifndef CPB_RENDERER_H
#define CPB_RENDERER_H

/* Register a bar for rendering */
void cpb_renderer_register_bar(void* bar);

/* Render all components */
void cpb_renderer_render_all(void);

/* Clear renderer state */
void cpb_renderer_clear(void);

#endif /* CPB_RENDERER_H */

