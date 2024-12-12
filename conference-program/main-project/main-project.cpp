#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №8. GIT\n";
    cout << "Вариант №0. Библиотечный отчет\n";
    cout << "Автор: Сергей Ермоченко\n\n";

    // Массив указателей на доклады
    Report* reports[MAX_FILE_ROWS_COUNT];

    int size;

    try {
        // Считываем данные из файла
        read("data.txt", reports, size);

        // Выводим содержимое
        for (int i = 0; i < size; i++) {
            cout << reports[i]->surname << '\n';
            cout << reports[i]->name << '\n';
            cout << reports[i]->patronymic << '\n';

            cout << "Время начала: " << setw(2) << setfill('0') << reports[i]->start / 100 << ":"
                << setw(2) << setfill('0') << reports[i]->start % 100 << '\n';

            cout << "Время окончания: " << setw(2) << setfill('0') << reports[i]->end / 100 << ":"
                << setw(2) << setfill('0') << reports[i]->end % 100 << '\n';

            cout << "Тема доклада: " << reports[i]->topic << '\n';
            cout << '\n';
        }

        // Освобождаем память
        for (int i = 0; i < size; i++) {
            delete reports[i];
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }

    return 0;
}
