#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>
#include <fstream>
using namespace std;


void menu() {
    cout << "Выберете действие: " << endl;
    cout << "1) Ввод массива структур" << endl;
    cout << "2) Вывод массива структур" << endl;
    cout << "3) Сортировка массива структур" << endl;
    cout << "4) Поиск в массиве структур по заданному параметру" << endl;
    cout << "5) Изменение заданной структуры" << endl;
    cout << "6) Удаление структуры из массива" << endl;
    cout << "7) Добавление в структуру" << endl;
    cout << "8) Выход" << endl;
}

union age
{
    int age;
    char birthday[10];
};

enum Faculty
{
    Фэис,
    Фисэ,
    СФ
};

struct students 
{
    char firstName[100];
    char secondName[100];
    char thirdName[100];
    char adress[500];
    char crew[10];
    int score;
    Faculty f;
    age a;
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "");

    int command, count, defend = 0, alert = 0;
    string faculty[3] = {"ФЭИС","ФИСЭ","СФ"};
    ofstream f; f.open("C://test.txt", fstream::out);
   
    cout << "Сколько будет людей: " << endl;
    cin >> count;
    system("cls");
    vector<students> person(count);
    menu();

    cin >> command;
    while (command != 8)
    {
        if (defend == 0 && (command > 1 && command < 8))
        {
            system("cls");
            command = 1;
            defend++;
        }

        else if (alert > count)
        {
            system("pause");
            system("cls");
            cout << "Cначало введи структуру нормально, припиздок!" << endl;
            command = 8;
        }

        else if (defend > 1 && command == 1)
            command = 7;
   
        switch (command)
        {
        // ввод
        case 1:
        {
            int facult;
            if (defend == 1) 
            {
                system("cls");
                cout << "Сначала введите структуру " << endl << endl;
                for (int i = 0; i < count; i++)
                {
                    cout << endl << "Введите информацию " << i + 1 << " человека" << endl;
                    cout << endl << "Введите Фамилию: ";
                    cin >> person[i].secondName;
                    cout << endl << "Введите Имя: ";
                    cin >> person[i].firstName;
                    cout << endl << "Введите Отчество: ";
                    cin >> person[i].thirdName;
                    cin.ignore(); 
                    cout << endl << "Введите домашний адрес: ";
                    cin.getline(person[i].adress, 500);
                    cout << endl << "Введите группу студента:  ";
                    cin.getline(person[i].crew, 10);
                    cout << endl << "Введите рейтинг студента:  ";
                    cin >> person[i].score;
                    cout << endl << "Введите дату рождения студента:  ";
                    cin >> person[i].a.birthday;
                    cout << endl << "Введите возраст студента:  ";
                    cin >> person[i].a.age;
                    cout << endl << "Введите факультет:  " << endl;
                    cout << "1) " << faculty[0] << endl
                         << "2) " << faculty[1] << endl
                         << "3) " << faculty[2] << endl;
                    cin >> facult;
                    switch (facult)
                    {
                    case 1:
                    {
                        person[i].f = Фэис;
                        break;
                    }
                    case 2:
                    {
                        person[i].f = Фисэ;
                        break;
                    }
                    case 3:
                    {
                        person[i].f = СФ;
                        break;
                    }
                    default:
                    {
                        person[i].f = СФ;
                        break;
                    }
                    }
                    cout << endl << endl;
                    alert++;                  
                }
                defend++;
            }

            else if (defend == 0)
            {
                system("cls");
                for (int i = 0; i < count; i++)
                {
                    cout << "Введите информацию " << i + 1 << " человека" << endl;
                    cout << endl << "Введите Фамилию: ";
                    cin >> person[i].secondName;
                    cout << endl << "Введите Имя: ";
                    cin >> person[i].firstName;
                    cout << endl << "Введите Отчество: ";
                    cin >> person[i].thirdName;
                    cin.ignore();
                    cout << endl << "Введите домашний адрес: ";
                    cin.getline(person[i].adress, 500);
                    cout << endl << "Введите группу студента:  ";
                    cin.getline(person[i].crew, 10);
                    cout << endl << "Введите рейтинг студента:  ";
                    cin >> person[i].score;
                    cout << endl << "Введите дату рождения студента:  ";
                    cin >> person[i].a.birthday;
                    cout << endl << "Введите возраст студента:  ";
                    cin >> person[i].a.age;
                    cout << endl << "Введите факультет:  " << endl;
                    cout << "1) " << faculty[0] << endl
                        << "2) " << faculty[1] << endl
                        << "3) " << faculty[2] << endl;
                    cin >> facult;
                    switch (facult)
                    {
                    case 1:
                    {
                        person[i].f = Фэис;
                        break;
                    }
                    case 2:
                    {
                        person[i].f = Фисэ;
                        break;
                    }
                    case 3:
                    {
                        person[i].f = СФ;
                        break;
                    }
                    default:
                    {
                        person[i].f = СФ;
                        break;
                    }
                    }
                    cout << endl << endl;
                    alert++;
                }
                defend += 2;
            }

            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        // вывод
        case 2:
        {
            for (int i = 0; i < count; i++)
            {
                cout << i + 1 << " студент:" << endl;
                cout << endl << "Фамилия: " << person[i].secondName;
                cout << endl << "Имя: " << person[i].firstName;
                cout << endl << "Отчество: " << person[i].thirdName;
                cout << endl << "Домашний адрес: " << person[i].adress;
                cout << endl << "Группа: " << person[i].crew;
                cout << endl << "Рейтинг: " << person[i].score << " баллов";
                cout << endl << "Дата рождения:  " << person[i].a.birthday;
                cout << endl << "Возраст:  " << person[i].a.age;
                cout << endl << "Факультет:  " << faculty[person[i].f];
                cout << endl;
            }

            for (int i = 0; i < count; i++) 
            {
                f << endl << i + 1 << "Студент: " << endl;
                f << "Фамилия: " << person[i].secondName << endl;
                f << "Имя: " << person[i].firstName << endl;
                f << "Отчество: " << person[i].thirdName << endl;
                f << "Домашний адрес: " << person[i].adress << endl;
                f << "Группа: " << person[i].crew << endl;
                f << "Рейтинг: " << person[i].score << " баллов" << endl;
                f << "Дата рождения: " << person[i].a.birthday << endl;
                f << "Возраст: " << person[i].a.age << endl;
                f << "Факультет: " << faculty[person[i].f] << endl << endl;
            }
            f.close();

            system("pause");
            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        // сортировка
        case 3:
        {
            for (int i = 0; i < count; i++)
            {
                for (int j = i; j < count; j++)
                {
                    if (strcmp(person[j].secondName, person[i].secondName) < 0)
                    {
                        swap(person[i].secondName, person[j].secondName);
                    }
                }
            }

            for (int i = 0; i < count; i++)
                cout << person[i].secondName << endl;

            cout << "Структура успешно отсортирована " << endl;
            system("pause");
            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        // поиск
        case 4:
        {
            int choice;
            cout << "По какому параметру будем искать?"
                << endl << "1) Имя: "
                << endl << "2) Фамилия: "
                << endl << "3) Отчество: "
                << endl << "4) Домашний адрес: "
                << endl << "5) Группа студента: "
                << endl << "6) Рейтинг студента: "
                << endl << "7) Возраст"
                << endl << "8) Факультет";
            cout << endl;
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
            {
                int tmp = 0;
                char name[100];
                cout << "Введите Имя: ";
                cin >> name;
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if (!strcmp(name, person[i].firstName))
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено" << endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            case 2:
            {
                int tmp = 0;
                char fam[100];
                cout << "Введите Фамилию: ";
                cin >> fam;
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if (!strcmp(fam, person[i].secondName))
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено" << endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            case 3:
            {
                int tmp = 0;
                char ot[100];
                cout << "Введите Отчество: ";
                cin >> ot;
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if (!strcmp(ot, person[i].thirdName))
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено" << endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            case 4:
            {
                int tmp = 0;
                char adress[500];
                cout << "Введите домашний адрес: ";
                cin.ignore();
                cin.getline(adress, 500);
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if (!strcmp(adress, person[i].adress))
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено" << endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            case 5:
            {
                int tmp = 0;
                char crew[10];
                cout << "Введите группу студента: ";
                cin.ignore();
                cin.getline(crew, 10);
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if (!strcmp(crew, person[i].crew))
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено"<<endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            case 6:
            {
                int tmp = 0;
                int score;
                cout << "Введите рейтинг студента: ";
                cin >> score;
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if ((int)score == (int)person[i].score)
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                    cout << "Ничего не найдено" << endl;
                system("pause");
                break;
            }
            case 7:
            {
                int tmp = 0;
                int age;
                cout << "Введите возраст студента: ";
                cin >> age;
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if ((int)age == (int)person[i].a.age)
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено" << endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            case 8:
            {
                int tmp = 0;
                string facult;
                cout << "Введите факультет: ";
                cin >> facult;
                cout << endl;
                for (int i = 0; i < count; i++)
                {
                    if (facult == faculty[person[i].f])
                    {
                        cout << endl << "Фамилия: " << person[i].secondName;
                        cout << endl << "Имя: " << person[i].firstName;
                        cout << endl << "Отчество: " << person[i].thirdName;
                        cout << endl << "Домашний адрес: " << person[i].adress;
                        cout << endl << "Группа: " << person[i].crew;
                        cout << endl << "Рейтинг: " << person[i].score << " баллов";
                        cout << endl << "Дата рождения:  " << person[i].a.birthday;
                        cout << endl << "Возраст:  " << person[i].a.age;
                        cout << endl << "Факультет:  " << faculty[person[i].f];
                        cout << endl;
                        tmp++;
                    }
                }
                if (tmp == 0)
                {
                    cout << "Ничего не найдено" << endl;
                    tmp++;
                }
                system("pause");
                break;
            }
            default:
                break;
            }
            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        // изменение
        case 5:
        {
            int tmp, facult;
            for (int i = 0; i < count; i++)
            {
                cout << i + 1 << " студент:" << endl;
                cout << endl << "Фамилия: " << person[i].secondName;
                cout << endl << "Имя: " << person[i].firstName;
                cout << endl << "Отчество: " << person[i].thirdName;
                cout << endl << "Домашний адрес: " << person[i].adress;
                cout << endl << "Группа: " << person[i].crew;
                cout << endl << "Рейтинг: " << person[i].score << " баллов";
                cout << endl << "Дата рождения:  " << person[i].a.birthday;
                cout << endl << "Возраст:  " << person[i].a.age;
                cout << endl << "Факультет:  " << faculty[person[i].f];
                cout << endl;
            }

            cout << "Введите порядковый номер человека, которого хотите изменить: ";
            cin >> tmp;

            cout << endl << "Введите Фамилию: ";
            cin >> person[tmp - 1].secondName;
            cout << endl << "Введите Имя: ";
            cin >> person[tmp - 1].firstName;
            cout << endl << "Введите Отчество: ";
            cin >> person[tmp - 1].thirdName;
            cin.ignore();
            cout << endl << "Введите домашний адрес: ";
            cin.getline(person[tmp - 1].adress, 500);
            cout << endl << "Введите группу студента:  ";
            cin.getline(person[tmp - 1].crew, 10);
            cout << endl << "Введите рейтинг студента:  ";
            cin >> person[tmp - 1].score;
            cout << endl << "Введите дату рождения студента:  ";
            cin >> person[tmp - 1].a.birthday;
            cout << endl << "Введите возраст студента:  ";
            cin >> person[tmp - 1].a.age;
            cout << endl << "Введите факультет:  ";
            cout << "1) " << faculty[0] << endl
                 << "2) " << faculty[1] << endl
                 << "3) " << faculty[2] << endl;
            cin >> facult;
            switch (facult)
            {
            case 1:
            {
                person[tmp - 1].f = Фэис;
                break;
            }
            case 2:
            {
                person[tmp - 1].f = Фисэ;
                break;
            }
            case 3:
            {
                person[tmp - 1].f = СФ;
                break;
            }
            default:
            {
                person[tmp - 1].f = СФ;
                break;
            }
            }
            cout << endl << endl;
            
            system("pause");
            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        // удаление
        case 6:
        {
            int choice;
            if (count == 1)
                cout << "Всего " << count << " студент, хочешь его удалить? ";
            else if (count > 1 && count < 5)
                cout << "Всего " << count << " студента , кого хочешь удалить? ";
            else if (count > 4)
                cout << "Всего " << count << " студентов , кого хочешь удалить? ";

            for (int i = 0; i < count; i++)
            {
                cout << endl << i + 1 << " студент:" << endl;
                cout << endl << "Фамилия: " << person[i].secondName;
                cout << endl << "Имя: " << person[i].firstName;
                cout << endl << "Отчество: " << person[i].thirdName;
                cout << endl << "Домашний адрес: " << person[i].adress;
                cout << endl << "Группа: " << person[i].crew;
                cout << endl << "Рейтинг: " << person[i].score << " баллов";
                cout << endl << "Дата рождения:  " << person[i].a.birthday;
                cout << endl << "Возраст:  " << person[i].a.age;
                cout << endl << "Факультет:  " << faculty[person[i].f];
                cout << endl;
            }

            cin >> choice;
            if ((choice <= count) && choice > 0)
            {
                for (int i = choice - 1; i < count - 1; i++)
                {
                    person[i] = person[i + 1];
                }
                count--;
            }

            else if (choice == 0)
            {
                cout << "Удаление отменено";
                cout << endl;
            }

            else
                cout << " ^ Invalid syntax";

            system("pause");
            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        case 7:
        {
            int facult, tmp;
            cout << "Сколько вы хотите добавить студентов?" << endl;
            cin >> tmp;
            count += tmp;
            person.resize(count);

            for (int i = count-tmp; i < count; i++)
            {
                cout << endl << "Введите информацию " << i + 1 << " человека" << endl;
                cout << endl << "Введите Фамилию: ";
                cin >> person[i].secondName;
                cout << endl << "Введите Имя: ";
                cin >> person[i].firstName;
                cout << endl << "Введите Отчество: ";
                cin >> person[i].thirdName;
                cin.ignore();
                cout << endl << "Введите домашний адрес: ";
                cin.getline(person[i].adress, 500);
                cout << endl << "Введите группу студента:  ";
                cin.getline(person[i].crew, 10);
                cout << endl << "Введите рейтинг студента:  ";
                cin >> person[i].score;
                cout << endl << "Введите дату рождения студента:  ";
                cin >> person[i].a.birthday;
                cout << endl << "Введите возраст студента:  ";
                cin >> person[i].a.age;
                cout << endl << "Введите факультет:  " << endl;
                cout << "1) " << faculty[0] << endl
                    << "2) " << faculty[1] << endl
                    << "3) " << faculty[2] << endl;
                cin >> facult;
                switch (facult)
                {
                case 1:
                {
                    person[i].f = Фэис;
                    break;
                }
                case 2:
                {
                    person[i].f = Фисэ;
                    break;
                }
                case 3:
                {
                    person[i].f = СФ;
                    break;
                }
                default:
                {
                    person[i].f = СФ;
                    break;
                }
                }
                cout << endl << endl;
            }
            system("pause");
            system("cls");
            menu();
            cin >> command;
            system("cls");
            break;
        }
        default:
        {
            command = 8;
            break;
        }
        }
    }

    cin.get();
    return 0;
}