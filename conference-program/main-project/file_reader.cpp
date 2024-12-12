#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void read(const std::string& filename, Report* reports[], int& size) {
    std::ifstream file(filename);
    size = 0;

    if (!file.is_open()) {
        throw "Ошибка: не удалось открыть файл.";
    }

    std::string line;
    while (std::getline(file, line) && size < MAX_FILE_ROWS_COUNT) {
        std::istringstream iss(line);
        Report* report = new Report;

        iss >> report->start >> report->end;
        iss >> report->surname >> report->name >> report->patronymic;

        std::getline(iss, report->topic);
        report->topic.erase(0, report->topic.find_first_not_of(" ")); // Убираем пробелы

        reports[size++] = report;
    }

    file.close();
}
