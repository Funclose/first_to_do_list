#pragma once
#include <iostream>
#include "search.h"

using namespace std;

void addTask(Task taskList[], int& taskCount)
{
    if (taskCount >= MAX_TASKS) {
        std::cout << "ƒостигнуто максимальное количество задач." << endl;
        return;
    }
    cout << "¬ведите дату создани€ пример(15.07.2003): ";
    cin.getline(taskList[taskCount].dateCreation, 11);
    

    std::cout << "¬ведите название задачи: ";
    std::cin.getline(taskList[taskCount].name, 50);

    std::cout << "¬ведите приоритет задачи: ";
    std::cin.getline(taskList[taskCount].priority, 50);

    std::cout << "¬ведите описание задачи: ";
    std::cin.getline(taskList[taskCount].description, 255);

    std::cout << "¬ведите количество дней на выполнение задачи (дней): ";
    std::cin >> taskList[taskCount].day;

    std::cout << "¬ведите врем€ на выполнение задачи (недель): ";
    std::cin >> taskList[taskCount].week;

    std::cout << "¬ведите врем€ выполнени€ задачи (мес€цей): ";
    std::cin >> taskList[taskCount].month;

    /*std::cout << "¬ведите врем€ на выполнени€ задачи(минуты): ";
    std::cin >> taskList[taskCount].minute;*/

    

    // счетчик задач
    taskCount++;

}

void deleteTasks(Task taskList[], int& taskCount, int index)
{
    if (index >= 0 && index < taskCount)
    {
        for (int i = index; i < taskCount - 1; i++)
        {
            taskList[i] = taskList[i + 1];
        }
        taskCount--;
        std::cout << "задача удалена!";
    }
    else
    {
        std::cout << "Ќеверный индекс!";
    }
}


void editTask(Task& task)
{
    std::cout << "¬ведите новое название задачи: ";
    std::cin.ignore();//очистка буфера перед getline
    std::cin.getline(task.name, 50);

    std::cout << "¬ведите новый приоритет задачи: ";
    std::cin.getline(task.priority, 50);

    std::cout << "¬ведите новое описание задачи: ";
    std::cin.getline(task.description, 50);

    std::cout << "новое количество мес€цов: ";
    std::cin >> task.month;
    std::cout << "новое количество дней: ";
    std::cin >> task.day;
    std::cout << "новое количество часов: ";
    std::cin >> task.hour;
    std::cout << "новое количество минут: ";
    std::cin >> task.minute;
}