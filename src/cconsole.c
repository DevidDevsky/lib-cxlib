#include <stdio.h>
#include <stdarg.h>
#include "cconsole.h"

// Реализация цветного printf
void cprintf(ccolor_t color, const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Устанавливаем цвет ANSI escape sequence
    printf("\033[%dm", color);

    // Печатаем текст
    vprintf(format, args);

    // Сбрасываем цвет
    printf("\033[0m");

    va_end(args);
}