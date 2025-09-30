@echo off
echo Сборка cxlib для Windows...
mkdir build
gcc -Wall -Iinclude -c src\*.c
ar rcs libcxlib.a src\*.o

echo Копирование файлов...
copy include\*.h C:\mingw\include
copy libcxlib.a C:\mingw\lib

echo Установка завершена! cxlib готова к использованию.
pause