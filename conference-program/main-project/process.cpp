#include "processing.h"
#include <iostream>

int calculateDuration(const Report* report) {
    int startHours = report->start / 100;
    int startMinutes = report->start % 100;
    int endHours = report->end / 100;
    int endMinutes = report->end % 100;

    // Вычисляем разницу в минутах
    int totalMinutes = (endHours * 60 + endMinutes) - (startHours * 60 + startMinutes);

    // Преобразуем разницу в часы и минуты
    int durationHours = totalMinutes / 60;
    int durationMinutes = totalMinutes % 60;

    // Преобразуем в формат ЧЧММ
    return durationHours * 100 + durationMinutes;
}


int process(Report* array[], int size) {
    if (size == 0) {
        return -1;
    }

    int longestIndex = 0;
    int maxDuration = calculateDuration(array[0]);

    for (int i = 1; i < size; ++i) {
        int currentDuration = calculateDuration(array[i]);
        if (currentDuration > maxDuration) {
            maxDuration = currentDuration;
            longestIndex = i;
        }
    }

    return calculateDuration(array[longestIndex]);
}
