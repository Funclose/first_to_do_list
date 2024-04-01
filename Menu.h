#pragma once
#include <iostream>
#include "search.h"
#include "Tasks.h"
#include "files.h"

void menu()
{
    setlocale(LC_ALL, "ru");
    Task taskList[MAX_TASKS];
    int taskCount = 0;

    char choice;
    do {
        cout << "����:" << endl;
        cout << "1. �������� ������" << endl;
        cout << "2. ������� ������ �����" << endl;
        cout << "3. ������� ������" << endl;
        cout << "4. ������������� ������" << endl;
        cout << "5. ����� �� ��������" << endl;
        cout << "6. �������� ������ � ����" << endl;
        cout << "7. ������� ������ �� �����" << endl;
        cout << "8. ������� ��� ������ �� �����" << endl;
        cout << "9. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        cin.ignore(); // ������� ������

        switch (choice) {
            //��������� ������
        case '1':
            addTask(taskList, taskCount);
            break;
            //���������� ���� ������ ��� ��������� ������
        case '2':
            int extraChoice;
            do {
                cout << "-----------------------------------" << endl;
                cout << "�������� ������ ��� ��������� �����:" << endl;
                cout << "1. �� ����" << endl;
                cout << "2. �� ������" << endl;
                cout << "3. �� �����" << endl;
                cout << "4. ���������� ��� ������ �����" << endl;
                cout << "5. �����" << endl;
                cout << "-----------------------------------" << endl;
                cout << "�������� ��������: ";

                cin >> extraChoice;
                cin.ignore(); // ������� ����� �����

                ///////// ������� ������ �� ��������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                switch (extraChoice)
                {
                case 1:
                {
                    char date[11];
                    std::cout << "������� ���� � ������� (dd.mm.yyyy): ";
                    std::cin.getline(date, sizeof(date));
                    printTasksForDay(taskList, taskCount, date);
                    break;
                }
                case 2:
                    printTasksForWeek(taskList, taskCount, taskList[taskCount].week);
                    break;
                case 3:
                    printTasksForMonth(taskList, taskCount, taskList[taskCount].month);//tyt ne zakonchil
                    break;
                case 4:
                    printTasks(taskList, taskCount);
                    break;

                default:
                    cout << "error number not found!";
                    break;
                }
            } while (extraChoice != 5);


            break;
            //��������
        case '3':
            int indexDelete;
            cout << "������� ������ ������� ������ �������: ";
            cin >> indexDelete;
            deleteTasks(taskList, taskCount, indexDelete - 1);// -1 ������ ��� �������� � 0
            break;
            //��������������
        case '4':
            int indexToEdit;
            cout << "������� ����� ������ ��� ��������������: ";
            cin >> indexToEdit;
            cin.ignore();
            if (indexToEdit >= 1 && indexToEdit <= taskCount)
            {
                cout << "�������������� ������ ����� " << indexToEdit << ":" << endl;
                editTask(taskList[indexToEdit - 1]);

            }
            else
            {
                cout << "�������� ����� ������." << endl;
            }
            break;
            //����� �� ���������� �� ���� (���, ���������)
        case '5':
            int userChoice;
            cout << "�������� ��� ������ �����: " << endl;
            /*cin.ignore();*/
            cout << "1. ����� �� �����" << endl;
            cout << "2. ����� �� ����������" << endl;
            cout << "3. ����� �� ��������" << endl;
            cout << "4. ����� �� ����" << endl;
            cout << "��� �����: ";
            cin >> userChoice;
            cin.ignore();   //<-- �������� ���� � ������ ������
            //���� � �����, ��� ��������������� ������
            switch (userChoice)
            {
            case 1:
                char nameToSearch[50];
                cout << "������� ��� ������ ��� ������:";
                cin.getline(nameToSearch, 50);
                searchByName(taskList, taskCount, nameToSearch);
                break;
            case 2:
                char priorityToSearch[50];
                cout << "������� ��������� ������ ��� ������:";
                cin.getline(priorityToSearch, 50);
                searchByPriority(taskList, taskCount, priorityToSearch);
                break;
            case 3:
                char descriptionToSearch[50];
                cout << "������� �������� ������ ��� ������:";
                cin.getline(descriptionToSearch, 50);
                searchByDescription(taskList, taskCount, descriptionToSearch);
                break;
            case 4:
                /*int day, month, year, hour, minute;
                cout << "������� ���� � ����� ��� ������:" << endl;
                cout << "����: "; cin >> day;
                cout << "�����: "; cin >> month;
                cout << "���: "; cin >> year;
                cout << "���: "; cin >> hour;
                cout << "������: "; cin >> minute;
                searchByDateTime(taskList, taskCount, day, month, year, hour, minute);*/
                break;

            default:
                cout << "error digit";
                break;
            }
            //���� �������
        case '6':
            saveTasksToFile(taskList, taskCount, "test.txt");
            break;
        case '7':
            clearFile("test.txt");
        case '8': 
            printFile("test.txt");
            break;
        case '9':
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� ����. ���������� ��� ���." << endl;
        }
    } while (choice != '9');
}


