# Akinator (Угадай персонажа)

[![CMake](https://img.shields.io/badge/CMake-3.10+-blue.svg)](https://cmake.org/)
[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://en.cppreference.com/w/cpp/17)

Консольная реализация игры "Акинатор" на C++ с использованием бинарного дерева для хранения базы вопросов и персонажей.

## Особенности
-  Угадывает загаданного персонажа по ответам на вопросы
-  Поддержка русского и английского языков
-  Сохранение и загрузка базы данных
-  Простое добавление новых персонажей в процессе игры

## Сборка и запуск
```bash
git clone https://github.com/ваш-username/Akinator.git
cd Akinator
mkdir build && cd build
cmake ..
make
./Akinator
