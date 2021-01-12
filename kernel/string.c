#include "string.h"

#include <stdarg.h>

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

char *strcpy(char *dest, const char *src) {
  int index = 0;
  while (src[index] != '\0') {
    dest[index] = src[index];
    index++;
  }
  dest[index] = '\0';
  return dest;
}

int sprintf(char *str, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  int index = 0;
  for (int i = 0; fmt[i] != '\0';) {
    switch (fmt[i++]) {
      case '\\':
        str[index++] = fmt[i++];
        break;
      case '%':
        // TODO
        break;
      default:
        str[index++] = fmt[i - 1];
        break;
    }
  }
  str[index++] = '\0';
  va_end(args);
  return index;
}