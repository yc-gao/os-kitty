#include "string.h"
#include "terminal.h"

char str[100];

void kernel_main(void) {
  /* Initialize terminal interface */
  terminal_initialize();

  sprintf(str, "calculate sum of 3, 4: %d\n", 3 + 4);
  terminal_puts(str);

  sprintf(str, "address of str: %x\n", str);
  terminal_puts(str);
}