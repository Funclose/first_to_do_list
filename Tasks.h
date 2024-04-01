#pragma once
#include <iostream>
#include "search.h"

using namespace std;

void addTask(Task taskList[], int& taskCount)
{
    if (taskCount >= MAX_TASKS) {
        std::cout << "���������� ������������ ���������� �����." << endl;
        return;
    }
    cout << "������� ���� �������� ������(15.07.2003): ";
    cin.getline(taskList[taskCount].dateCreation, 11);
    

    std::cout << "������� �������� ������: ";
    std::cin.getline(taskList[taskCount].name, 50);

    std::cout << "������� ��������� ������: ";
    std::cin.getline(taskList[taskCount].priority, 50);

    std::cout << "������� �������� ������: ";
    std::cin.getline(taskList[taskCount].description, 255);

    std::cout << "������� ���������� ���� �� ���������� ������ (����): ";
    std::cin >> taskList[taskCount].day;

    std::cout << "������� ����� �� ���������� ������ (������): ";
    std::cin >> taskList[taskCount].week;

    std::cout << "������� ����� ���������� ������ (�������): ";
    std::cin >> taskList[taskCount].month;

    /*std::cout << "������� ����� �� ���������� ������(������): ";
    std::cin >> taskList[taskCount].minute;*/

    

    // ������� �����
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
        std::cout << "������ �������!";
    }
    else
    {
        std::cout << "�������� ������!";
    }
}


void editTask(Task& task)
{
    std::cout << "������� ����� �������� ������: ";
    std::cin.ignore();//������� ������ ����� getline
    std::cin.getline(task.name, 50);

    std::cout << "������� ����� ��������� ������: ";
    std::cin.getline(task.priority, 50);

    std::cout << "������� ����� �������� ������: ";
    std::cin.getline(task.description, 50);

    std::cout << "����� ���������� �������: ";
    std::cin >> task.month;
    std::cout << "����� ���������� ����: ";
    std::cin >> task.day;
    std::cout << "����� ���������� �����: ";
    std::cin >> task.hour;
    std::cout << "����� ���������� �����: ";
    std::cin >> task.minute;
}