#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "search.h"
#include <sstream>

void printTasksForDay(const Task taskList[], int taskCount, const char* dateCreation)
{
    cout << "������ ����� �� " << dateCreation << ":\n";
    bool found = false; // ���� ��� ������������ ������� ����� �� ��������� ����

    for (int i = 0; i < taskCount; ++i) {
        // �������� ���� �������� ������ �� ����, ����� � ���
        int taskDay, taskMonth, taskYear;
        sscanf(taskList[i].dateCreation, "%d.%d.%d", &taskDay, &taskMonth, &taskYear);

        // ��������� ��������� ������������� ���� �� ����, ����� � ���
        int inputDay, inputMonth, inputYear;
        sscanf(dateCreation, "%d.%d.%d", &inputDay, &inputMonth, &inputYear);

        // ���������� ����
        if (taskDay == inputDay && taskMonth == inputMonth && taskYear == inputYear) {
            found = true;
            cout << "������ " << i + 1 << ":" << endl;
            cout << "��������: " << taskList[i].name << endl;
            cout << "���������: " << taskList[i].priority << endl;
            cout << "��������: " << taskList[i].description << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "��� ����� �� ��������� ����." << endl;
    }
}
void printTasksForWeek(const Task taskList[], int taskCount, int week)
{
    cout << "������ ����� �� ������:" << endl;
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (taskList[i].week > 0) {
            cout << "������ " << i + 1 << ":" << endl;
            cout << "��������: " << taskList[i].name << endl;
            cout << "���������: " << taskList[i].priority << endl;
            cout << "��������: " << taskList[i].description << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "��� ����� �� ������� ������." << endl;
    }
}
void printTasksForMonth(const Task taskList[], int taskCount, int month)
{
	cout << "������ ����� �� �����: " << endl;
    bool found = false;
    for (int i = 0; i < taskCount; ++i) {
        if (taskList[i].month > 0) {
            cout << "������ " << i + 1 << ":" << endl;
            cout << "��������: " << taskList[i].name << endl;
            cout << "���������: " << taskList[i].priority << endl;
            cout << "��������: " << taskList[i].description << endl;
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "��� ����� �� ������� �����." << endl;
    }
}