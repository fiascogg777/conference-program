#include "processing.h"
#include <iostream>

int calculateDuration(const Report* report) {
    int startHours = report->start / 100;
    int startMinutes = report->start % 100;
    int endHours = report->end / 100;
    int endMinutes = report->end % 100;

    return (endHours * 60 + endMinutes) - (startHours * 60 + startMinutes);
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

    std::cout << array[longestIndex]; 
    return 0;
}
