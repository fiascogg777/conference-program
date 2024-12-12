#include <iostream>
#include <iomanip>
#include <vector>
#include "file_reader.h"
#include "constants.h"
#include "Report.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �8. GIT\n";
    cout << "������� �0. ������������ �����\n";
    cout << "�����: ������ ���������\n\n";
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

    return 0;
}
