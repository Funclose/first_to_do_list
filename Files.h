#pragma once
#include <iostream>
#include <fstream>
#include "search.h"
#include "Tasks.h"
#include "Menu.h"

void saveTasksToFile(const Task taskList[], int taskCount, const char* filename) {
    std::cout << endl;
    FILE* file = std::fopen(filename, "w");
    if (!file) {
        std::cout << "Ошибка открытия файла для записи\n";
        return;
    }

    for (int i = 0; i < taskCount; ++i) {
        std::fprintf(file, "Дата создания: %d.%d.%d\n", taskList[i].day, taskList[i].month, taskList[i].year); // error
        std::fprintf(file, "Название: %s\n", taskList[i].name);
        std::fprintf(file, "Пріоритет: %s\n", taskList[i].priority);
        std::fprintf(file, "Описание: %s\n", taskList[i].description);
        std::fprintf(file, "Срок на выполнение (дней): %d\n", taskList[i].day);
        std::fprintf(file, "Срок на выполнение (недель): %d\n", taskList[i].week);
        std::fprintf(file, "Срок на выполнение (месяцев): %d\n", taskList[i].month);
        std::fprintf(file, "-----------------------------------\n");
    }

    std::fclose(file);
    std::cout << "Задача успешно сохранена в файле: " << filename << std::endl;
}


void clearFile(const char* filename) {
    FILE* file = std::fopen(filename, "w"); // Открываем файл в режиме записи
    if (!file) {
        std::perror("Ошибка при открытии файла для очистки");
    }
    else {
        std::fclose(file); // Закрываем файл
        std::cout << "Файл успешно очищен: " << filename << std::endl;
    }
}


void printFile(const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "r") != 0) {
        std::cout << "Ошибка открытия файла: " << filename << std::endl; //
        return;
    }

    std::cout << "Содержимое файла " << filename << ":" << std::endl;
    char line[256];
    while (fgets(line, sizeof(line), file)) { // Читаем файл построчно
        std::cout << line; // Выводим содержимое строки
    }

    fclose(file); // Закрываем файл
}