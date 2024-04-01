#pragma once
#include <iostream>

const int MAX_TASKS = 100;
using namespace std;

struct Task
{
    char name[50];
    char priority[50];
    char description[255];
    char dateCreation[50];
    int day;
    int month;
    int week;
    int year;
    int hour;
    int minute;
    
};

void printTasks(const Task taskList[], int taskCount)
{
    std::cout << endl;
    std::cout << "Список задач:" << endl;
    if (taskCount == 0)
    {
        std::cout << "nety zadach" << endl;
    }
    for (int i = 0; i < taskCount; ++i)
    {
        std::cout << "-----------------------------------" << endl;
        std::cout<< "Дата создания: "<<taskList[i].dateCreation<< endl;
        std::cout << "Задача " << i + 1 << ":" << endl;
        std::cout << "Название: " << taskList[i].name << endl;
        std::cout << "Приоритет: " << taskList[i].priority << endl;
        std::cout << "Описание: " << taskList[i].description << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << endl;
        std::cout << "Срок на выполнение: " << endl;
        std::cout << "<.................................>" << endl;
        std::cout << "месяцей: " << taskList[i].month << endl;
        std::cout << "недель: " << taskList[i].week << endl;
        std::cout << "дней: " << taskList[i].day << endl;
        std::cout << "<.................................>" << endl;
        std::cout << endl;
    }
}


void searchByName(const Task taskList[], int taskCount, const char* name) {
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (strcmp(taskList[i].name, name) == 0) {
            std::cout << "Найдена задача с названием \"" << name << "\":" << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "Задачи с названием \"" << name << "\" не найдены." << std::endl;
    }
}

void searchByPriority(const Task taskList[], int taskCount, const char* priority) {
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (strcmp(taskList[i].priority, priority) == 0) {
            std::cout << "Найдена задача с приоритетом \"" << priority << "\":" << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "Задачи с приоритетом \"" << priority << "\" не найдены." << std::endl;
    }
}

void searchByDescription(const Task taskList[], int taskCount, const char* description) {
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (strcmp(taskList[i].description, description) == 0) {
            std::cout << "Найдена задача с описанием \"" << description << "\":" << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "Задачи с описанием \"" << description << "\" не найдены." << std::endl;
    }
}

void searchByDateTime(const Task taskList[], int taskCount, int day, int month, int year/*, int hour, int minute*/) {       //константный чар (раньше был int)
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (taskList[i].day == day && taskList[i].month == month && taskList[i].year == year /*&&
            taskList[i].hour == hour && taskList[i].minute == minute*/) {
            std::cout << "Найдена задача, которая должна быть выполнена " << day << "." << month << "." << year << " в "/* << hour << ":" << minute << ":"*/ << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "Задачи на " << day << "." << month << "." << year << " в " /*<< hour << ":" << minute*/ << " не найдены." << std::endl;
    }
}
