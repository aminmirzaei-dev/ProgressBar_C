#ifndef CPB_H
#define CPB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "bar.h"
#include "renderer.h"
#include "terminal.h"

/* Initialize the library (must be called once) */
void cpb_init(void);

/* Render all registered components */
void cpb_render(void);

/* Cleanup terminal state */
void cpb_shutdown(void);

#ifdef __cplusplus
}
#endif

#endif /* CPB_H */

