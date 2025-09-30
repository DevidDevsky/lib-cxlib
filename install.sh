#!/bin/bash

# Переходим в директорию скрипта
cd "$(dirname "$0")"

# Проверка Makefile
if [ ! -f Makefile ]; then
    echo "Ошибка: Makefile не найден!"
    exit 1
fi

echo "Сборка cxlib..."
make

echo "Копирование заголовков..."
sudo cp include/*.h /usr/local/include/

echo "Копирование библиотеки..."
sudo cp libcxlib.a /usr/local/lib/

echo "cxlib успешно установлена!"