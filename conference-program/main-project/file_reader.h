#ifndef FILE_READER_H
#define FILE_READER_H

#include "Report.h"
#include "constants.h"
#include <string>

void read(const std::string& filename, Report* reports[], int& size);

#endif // FILE_READER_H
