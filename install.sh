#!/bin/bash
set -e

echo "Сборка cxlib..."
mkdir -p build
cd build
make

echo "Копирование заголовков и библиотеки в /usr/local..."
sudo cp ../include/*.h /usr/local/include/
sudo cp libcxlib.a /usr/local/lib/

echo "Установка завершена!"
echo "Теперь можно подключать #include <cxlib.h> и линковать с -lcxlib"