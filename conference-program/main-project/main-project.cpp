#include <iostream>
#include <iomanip>
#include <vector>
#include "file_reader.h"
#include "constants.h"
#include "Report.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #2. Conference Program.\n";
    cout << "Author: Ivan Bobrov\n";
    cout << "Group: 24Ping1D\n";
    
    int size;
    Report** reports;
    // Считывание данных из файла
    read("data.txt", reports, size);

    if (reports.empty()) {
        cout << "Данные отсутствуют или произошла ошибка при чтении файла.\n";
        return 1;
    }

    cout << "***** Библиотечный отчет *****\n\n";
    for (const auto& report : reports) {
        /********** вывод читателя **********/
        cout << "Читатель........: ";
        cout << report.surname << " ";
        cout << report.name[0] << ". ";
        cout << report.patronymic[0] << ".\n";

        /********** вывод книги **********/
        cout << "Тема............: ";
        cout << '"' << report.topic << "\"\n";

        /********** вывод даты начала **********/
        cout << "Время начала.....: ";
        cout << setw(4) << setfill('0') << report.start << '\n';
            

        /********** вывод даты окончания **********/
        cout << "Время окончания..: ";
        cout << setw(2) << setfill('0') << report.end << '\n';
    }

   
}
