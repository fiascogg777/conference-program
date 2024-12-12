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
    // ���������� ������ �� �����
    read("data.txt", reports, size);

    if (reports.empty()) {
        cout << "������ ����������� ��� ��������� ������ ��� ������ �����.\n";
        return 1;
    }

    cout << "***** ������������ ����� *****\n\n";
    for (const auto& report : reports) {
        /********** ����� �������� **********/
        cout << "��������........: ";
        cout << report.surname << " ";
        cout << report.name[0] << ". ";
        cout << report.patronymic[0] << ".\n";

        /********** ����� ����� **********/
        cout << "����............: ";
        cout << '"' << report.topic << "\"\n";

        /********** ����� ���� ������ **********/
        cout << "����� ������.....: ";
        cout << setw(4) << setfill('0') << report.start << '\n';
            

        /********** ����� ���� ��������� **********/
        cout << "����� ���������..: ";
        cout << setw(2) << setfill('0') << report.end << '\n';
    }

   
}
