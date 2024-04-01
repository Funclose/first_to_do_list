#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "search.h"
#include <sstream>

void printTasksForDay(const Task taskList[], int taskCount, const char* dateCreation)
{
    cout << "Список задач на " << dateCreation << ":\n";
    bool found = false; // Флаг для отслеживания наличия задач на указанную дату

    for (int i = 0; i < taskCount; ++i) {
        // Разбиваю дату создания задачи на день, месяц и год
        int taskDay, taskMonth, taskYear;
        sscanf(taskList[i].dateCreation, "%d.%d.%d", &taskDay, &taskMonth, &taskYear);

        // Разбиваем введенную пользователем дату на день, месяц и год
        int inputDay, inputMonth, inputYear;
        sscanf(dateCreation, "%d.%d.%d", &inputDay, &inputMonth, &inputYear);

        // Сравниваем даты
        if (taskDay == inputDay && taskMonth == inputMonth && taskYear == inputYear) {
            found = true;
            cout << "Задача " << i + 1 << ":" << endl;
            cout << "Название: " << taskList[i].name << endl;
            cout << "Приоритет: " << taskList[i].priority << endl;
            cout << "Описание: " << taskList[i].description << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет задач на указанную дату." << endl;
    }
}
void printTasksForWeek(const Task taskList[], int taskCount, int week)
{
    cout << "Список задач на неделю:" << endl;
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (taskList[i].week > 0) {
            cout << "Задача " << i + 1 << ":" << endl;
            cout << "Название: " << taskList[i].name << endl;
            cout << "Приоритет: " << taskList[i].priority << endl;
            cout << "Описание: " << taskList[i].description << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Нет задач на текущую неделю." << endl;
    }
}
void printTasksForMonth(const Task taskList[], int taskCount, int month)
{
	cout << "Список задач на месяц: " << endl;
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (taskList[i].month > 0) {
            cout << "Задача " << i + 1 << ":" << endl;
            cout << "Название: " << taskList[i].name << endl;
            cout << "Приоритет: " << taskList[i].priority << endl;
            cout << "Описание: " << taskList[i].description << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Нет задач на текущий месяц." << endl;
    }
}