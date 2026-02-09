#ifndef CPB_BAR_H
#define CPB_BAR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "color.h"

typedef struct cpb_bar cpb_bar_t;

void cpb_bar_set_fill_color(cpb_bar_t* bar, cpb_color_t color);
void cpb_bar_set_empty_color(cpb_bar_t* bar, cpb_color_t color);
void cpb_bar_set_label_color(cpb_bar_t* bar, cpb_color_t color);

/* Create a progress bar with a maximum value */
cpb_bar_t* cpb_bar_create(int max);

/* Set bar properties */
void cpb_bar_set_label(cpb_bar_t* bar, const char* label);
void cpb_bar_set_width(cpb_bar_t* bar, int width);

/* Progress control */
void cpb_bar_set(cpb_bar_t* bar, int value);
void cpb_bar_increment(cpb_bar_t* bar, int delta);
int  cpb_bar_is_finished(cpb_bar_t* bar);

/* Destroy bar */
void cpb_bar_destroy(cpb_bar_t* bar);

/* Internal: render bar */
void cpb_bar_render(const cpb_bar_t* bar);

#ifdef __cplusplus
}
#endif

#endif /* CPB_BAR_H */

