# CPB – Console Progress Bar Library (C / C++)

CPB is a lightweight, modular, and extensible **console progress bar library** written in C, designed to be easily usable from both **C and C++** projects.  
It provides a clean API, ANSI-based colored output, and flicker-free rendering of multiple progress bars in terminal applications.

---

## Features
- ✅ Simple and clean C API
- ✅ Works with both **C and C++**
- ✅ Multiple progress bars at the same time
- ✅ ANSI color support (customizable)
- ✅ Adjustable bar width
- ✅ Labels and percentage display
- ✅ Centralized renderer (no screen flicker)
- ✅ Modular and extensible architecture 

---

## Example: Basic Progress Bar

This example demonstrates creating a progress bar, configuring colors, and updating it.

```c
#include <unistd.h>     // usleep
#include <stdio.h>
#include "cpb/cpb.h"
#include "cpb/bar.h"
#include "cpb/color.h"

int main(void) {
    /* Initialize library */
    cpb_init();
    cpb_color_enable(1);

    /* Create a progress bar with max = 100 */
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

    /* Update progress */
    for (int i = 0; i <= 100; i++) {
        cpb_bar_set(bar, i);
        cpb_render();
        usleep(50000); /* 50ms delay */
    }

    /* Cleanup */
    cpb_bar_destroy(bar);
    cpb_shutdown();
    printf("\nDone!\n");
    return 0;
}
```

---

## Compilation Instructions

To compile the example on Linux or macOS:

```bash
gcc examples/basic_bar.c     src/core/cpb.c     src/core/bar.c     src/core/renderer.c     src/terminal/terminal_ansi.c     src/terminal/color_ansi.c     -Iinclude     -o basic_bar
```

Run:

```bash
./basic_bar
```

---

## Color Support

CPB supports ANSI colors for terminal output. Available colors:

- `CPB_COLOR_RED`  
- `CPB_COLOR_GREEN`  
- `CPB_COLOR_YELLOW`  
- `CPB_COLOR_BLUE`  
- `CPB_COLOR_MAGENTA`  
- `CPB_COLOR_CYAN`  
- `CPB_COLOR_WHITE`  
- `CPB_COLOR_DEFAULT`  

Enable or disable colors globally:

```c
cpb_color_enable(1); // enable
cpb_color_enable(0); // disable
```

---

## API Reference (Key Functions)

| Function | Description |
|----------|-------------|
| `cpb_init()` | Initialize CPB library and terminal |
| `cpb_shutdown()` | Restore terminal and clean up resources |
| `cpb_render()` | Render all registered progress bars |
| `cpb_bar_create(max)` | Create a progress bar with maximum value `max` |
| `cpb_bar_destroy(bar)` | Destroy a progress bar and free memory |
| `cpb_bar_set(bar, value)` | Set the current value of the progress bar |
| `cpb_bar_set_label(bar, "text")` | Set the label of the bar |
| `cpb_bar_set_width(bar, width)` | Set the width of the bar in characters |
| `cpb_bar_set_fill_color(bar, color)` | Set the fill color |
| `cpb_bar_set_empty_color(bar, color)` | Set the empty color |
| `cpb_bar_set_label_color(bar, color)` | Set the label color |
| `cpb_color_enable(0/1)` | Enable or disable ANSI color output |

---

## Notes and Limitations

- Uses ANSI escape sequences (works on Linux, macOS, WSL)  
- Native Windows console backend not implemented yet  
- Not thread-safe by design  

---

## Roadmap

Planned future improvements:

- Theme system (dark / light / custom)  
- ETA and speed calculation  
- Spinner / loading indicators  
- Native Windows backend  
- CMake build and install support  

---

## License

MIT License  
You are free to use, modify, and distribute this library in personal or commercial projects.

---

## Contributing

Issues, pull requests, and suggestions are welcome.  
This project is designed to be clean, educational, and easy to extend.

Enjoy building beautiful console tools 🚀
