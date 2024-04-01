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
        std::cout << "������ �������� ����� ��� ������\n";
        return;
    }

    for (int i = 0; i < taskCount; ++i) {
        std::fprintf(file, "���� ��������: %d.%d.%d\n", taskList[i].day, taskList[i].month, taskList[i].year); // error
        std::fprintf(file, "��������: %s\n", taskList[i].name);
        std::fprintf(file, "��������: %s\n", taskList[i].priority);
        std::fprintf(file, "��������: %s\n", taskList[i].description);
        std::fprintf(file, "���� �� ���������� (����): %d\n", taskList[i].day);
        std::fprintf(file, "���� �� ���������� (������): %d\n", taskList[i].week);
        std::fprintf(file, "���� �� ���������� (�������): %d\n", taskList[i].month);
        std::fprintf(file, "-----------------------------------\n");
    }

    std::fclose(file);
    std::cout << "������ ������� ��������� � �����: " << filename << std::endl;
}


void clearFile(const char* filename) {
    FILE* file = std::fopen(filename, "w"); // ��������� ���� � ������ ������
    if (!file) {
        std::perror("������ ��� �������� ����� ��� �������");
    }
    else {
        std::fclose(file); // ��������� ����
        std::cout << "���� ������� ������: " << filename << std::endl;
    }
}


void printFile(const char* filename) {
    FILE* file;
    if (fopen_s(&file, filename, "r") != 0) {
        std::cout << "������ �������� �����: " << filename << std::endl; //
        return;
    }

    std::cout << "���������� ����� " << filename << ":" << std::endl;
    char line[256];
    while (fgets(line, sizeof(line), file)) { // ������ ���� ���������
        std::cout << line; // ������� ���������� ������
    }

    fclose(file); // ��������� ����
}