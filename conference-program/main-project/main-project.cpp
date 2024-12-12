#include <iostream>
#include <iomanip>
#include <string>
#include "Report.h"
#include "file_reader.h"
#include "constants.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �8. GIT\n";
    cout << "������� �0. ������������ �����\n";
    cout << "�����: ������ ���������\n\n";

    // ������ ���������� �� �������
    Report* reports[MAX_FILE_ROWS_COUNT];

    int size;

    try {
        // ��������� ������ �� �����
        read("data.txt", reports, size);

        // ������� ����������
        for (int i = 0; i < size; i++) {
            cout << reports[i]->surname << '\n';
            cout << reports[i]->name << '\n';
            cout << reports[i]->patronymic << '\n';

            cout << "����� ������: " << setw(2) << setfill('0') << reports[i]->start / 100 << ":"
                << setw(2) << setfill('0') << reports[i]->start % 100 << '\n';

            cout << "����� ���������: " << setw(2) << setfill('0') << reports[i]->end / 100 << ":"
                << setw(2) << setfill('0') << reports[i]->end % 100 << '\n';

            cout << "���� �������: " << reports[i]->topic << '\n';
            cout << '\n';
        }

        // ����������� ������
        for (int i = 0; i < size; i++) {
            delete reports[i];
        }
    }
    catch (const char* error) {
        cout << error << '\n';
    }

    return 0;
}
