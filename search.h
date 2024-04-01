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
    std::cout << "������ �����:" << endl;
    if (taskCount == 0)
    {
        std::cout << "nety zadach" << endl;
    }
    for (int i = 0; i < taskCount; ++i)
    {
        std::cout << "-----------------------------------" << endl;
        std::cout<< "���� ��������: "<<taskList[i].dateCreation<< endl;
        std::cout << "������ " << i + 1 << ":" << endl;
        std::cout << "��������: " << taskList[i].name << endl;
        std::cout << "���������: " << taskList[i].priority << endl;
        std::cout << "��������: " << taskList[i].description << endl;
        std::cout << "-----------------------------------" << endl;
        std::cout << endl;
        std::cout << "���� �� ����������: " << endl;
        std::cout << "<.................................>" << endl;
        std::cout << "�������: " << taskList[i].month << endl;
        std::cout << "������: " << taskList[i].week << endl;
        std::cout << "����: " << taskList[i].day << endl;
        std::cout << "<.................................>" << endl;
        std::cout << endl;
    }
}


void searchByName(const Task taskList[], int taskCount, const char* name) {
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (strcmp(taskList[i].name, name) == 0) {
            std::cout << "������� ������ � ��������� \"" << name << "\":" << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "������ � ��������� \"" << name << "\" �� �������." << std::endl;
    }
}

void searchByPriority(const Task taskList[], int taskCount, const char* priority) {
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (strcmp(taskList[i].priority, priority) == 0) {
            std::cout << "������� ������ � ����������� \"" << priority << "\":" << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "������ � ����������� \"" << priority << "\" �� �������." << std::endl;
    }
}

void searchByDescription(const Task taskList[], int taskCount, const char* description) {
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (strcmp(taskList[i].description, description) == 0) {
            std::cout << "������� ������ � ��������� \"" << description << "\":" << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "������ � ��������� \"" << description << "\" �� �������." << std::endl;
    }
}

void searchByDateTime(const Task taskList[], int taskCount, int day, int month, int year/*, int hour, int minute*/) {       //����������� ��� (������ ��� int)
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (taskList[i].day == day && taskList[i].month == month && taskList[i].year == year /*&&
            taskList[i].hour == hour && taskList[i].minute == minute*/) {
            std::cout << "������� ������, ������� ������ ���� ��������� " << day << "." << month << "." << year << " � "/* << hour << ":" << minute << ":"*/ << std::endl;
            printTasks(&taskList[i], 1);
            found = true;
        }
    }
    if (!found) {
        std::cout << "������ �� " << day << "." << month << "." << year << " � " /*<< hour << ":" << minute*/ << " �� �������." << std::endl;
    }
}
