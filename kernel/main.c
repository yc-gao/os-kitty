#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "terminal.h"

void kernel_main(void) {
  /* Initialize terminal interface */
  terminal_initialize();

  /* Newline support is left as an exercise. */
  puts("Hello, kernel World!\n");
}