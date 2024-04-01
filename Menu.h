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
        cout << "Меню:" << endl;
        cout << "1. Добавить задачу" << endl;
        cout << "2. Вывести список задач" << endl;
        cout << "3. Удалить задачу" << endl;
        cout << "4. Редактировать задачу" << endl;
        cout << "5. Поиск по названию" << endl;
        cout << "6. записать задачи в файл" << endl;
        cout << "7. удалить данные из файла" << endl;
        cout << "8. вывести все задачи из файла" << endl;
        cout << "9. Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        cin.ignore(); // Очистка буфера

        switch (choice) {
            //добавляет задачу
        case '1':
            addTask(taskList, taskCount);
            break;
            //конкретный день недели для просмотра задачи
        case '2':
            int extraChoice;
            do {
                cout << "-----------------------------------" << endl;
                cout << "Выберите период для просмотра задач:" << endl;
                cout << "1. На день" << endl;
                cout << "2. На неделю" << endl;
                cout << "3. На месяц" << endl;
                cout << "4. посмотреть все списки задач" << endl;
                cout << "5. назад" << endl;
                cout << "-----------------------------------" << endl;
                cout << "Выберите действие: ";

                cin >> extraChoice;
                cin.ignore(); // Очищаем буфер ввода

                ///////// СДЕЛАТЬ ВООБЩЕ не работает!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                switch (extraChoice)
                {
                case 1:
                {
                    char date[11];
                    std::cout << "Введите дату в формате (dd.mm.yyyy): ";
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
            //удаление
        case '3':
            int indexDelete;
            cout << "введите задачу которую хотите удалить: ";
            cin >> indexDelete;
            deleteTasks(taskList, taskCount, indexDelete - 1);// -1 потому что начинаем с 0
            break;
            //редактирование
        case '4':
            int indexToEdit;
            cout << "Введите номер задачи для редактирования: ";
            cin >> indexToEdit;
            cin.ignore();
            if (indexToEdit >= 1 && indexToEdit <= taskCount)
            {
                cout << "редактирование задачи номер " << indexToEdit << ":" << endl;
                editTask(taskList[indexToEdit - 1]);

            }
            else
            {
                cout << "Неверный номер задачи." << endl;
            }
            break;
            //поиск за описинанию по типу (имя, приоритет)
        case '5':
            int userChoice;
            cout << "Выберите что хотите найти: " << endl;
            /*cin.ignore();*/
            cout << "1. Поиск по имени" << endl;
            cout << "2. Поиск по приоретету" << endl;
            cout << "3. поиск по описанию" << endl;
            cout << "4. поиск по дате" << endl;
            cout << "Ваш выбор: ";
            cin >> userChoice;
            cin.ignore();   //<-- проблема была в чистке буфера
            //кейс в кейсе, для дополнительного выбора
            switch (userChoice)
            {
            case 1:
                char nameToSearch[50];
                cout << "Введите имя задачи для поиска:";
                cin.getline(nameToSearch, 50);
                searchByName(taskList, taskCount, nameToSearch);
                break;
            case 2:
                char priorityToSearch[50];
                cout << "Введите приоритет задачи для поиска:";
                cin.getline(priorityToSearch, 50);
                searchByPriority(taskList, taskCount, priorityToSearch);
                break;
            case 3:
                char descriptionToSearch[50];
                cout << "Введите описание задачи для поиска:";
                cin.getline(descriptionToSearch, 50);
                searchByDescription(taskList, taskCount, descriptionToSearch);
                break;
            case 4:
                /*int day, month, year, hour, minute;
                cout << "Введите дату и время для поиска:" << endl;
                cout << "День: "; cin >> day;
                cout << "Месяц: "; cin >> month;
                cout << "Год: "; cin >> year;
                cout << "Час: "; cin >> hour;
                cout << "Минута: "; cin >> minute;
                searchByDateTime(taskList, taskCount, day, month, year, hour, minute);*/
                break;

            default:
                cout << "error digit";
                break;
            }
            //файл система
        case '6':
            saveTasksToFile(taskList, taskCount, "test.txt");
            break;
        case '7':
            clearFile("test.txt");
        case '8': 
            printFile("test.txt");
            break;
        case '9':
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
        }
    } while (choice != '9');
}


