// Модуль для работы с цветным выводом в консоль

#ifndef CCONSOLE_H
#define CCONSOLE_H

// Перечисление доступных цветов
typedef enum {
    C_BLACK   = 30,
    C_RED     = 31,
    C_GREEN   = 32,
    C_YELLOW  = 33,
    C_BLUE    = 34,
    C_MAGENTA = 35,
    C_CYAN    = 36,
    C_WHITE   = 37,
    C_RESET   = 0
} ccolor_t;

// Вывод текста в заданном цвете
void cprintf(ccolor_t color, const char *format, ...);

#endif // CCONSOLE_H