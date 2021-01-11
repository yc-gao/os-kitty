#include "string.h"

void *memcpy(void *dest, const void *src, size_t n) {
  for (size_t i = 0; i < n; ++i) {
    ((uint8_t *)dest)[i] = ((uint8_t *)src)[i];
  }
  return dest;
}

void *memset(void *s, int c, size_t n) {
  uint8_t *addr = s;
  while (n > 0) {
    *addr = c;
    addr++;
    n--;
  }
  return s;
}

size_t strlen(const char *s) {
  size_t l = 0;
  while (*s != '\0') {
    l++;
    s++;
  }
  return l;
}
