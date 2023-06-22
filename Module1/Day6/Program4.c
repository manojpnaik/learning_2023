#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

int compareFloat(const void* a, const void* b) {
    const LogEntry* entryA = (const LogEntry*)a;
    const LogEntry* entryB = (const LogEntry*)b;

    if (entryA->temperature < entryB->temperature)
        return 1;
    else if (entryA->temperature > entryB->temperature)
        return -1;
    else
        return 0;
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open file: data.csv\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Read and discard the header line

    int numEntries = 0;
    LogEntry* logArray = NULL;

    while (fgets(line, sizeof(line), file)) {
        LogEntry entry;
        char* token = strtok(line, ",");
        entry.entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entry.sensorNo, token, sizeof(entry.sensorNo));

        token = strtok(NULL, ",");
        entry.temperature = atof(token);

        token = strtok(NULL, ",");
        entry.humidity = atoi(token);

        token = strtok(NULL, ",");
        entry.light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entry.time, token, sizeof(entry.time));

        numEntries++;

        logArray = realloc(logArray, numEntries * sizeof(LogEntry));
        logArray[numEntries - 1] = entry;
    }

    fclose(file);

    qsort(logArray, numEntries, sizeof(LogEntry), compareFloat);

    file = fopen("sorted_data.csv", "w");
    if (file == NULL) {
        printf("Failed to create file: sorted_data.csv\n");
        free(logArray);
        return 1;
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Time\n");
    for (int i = 0; i < numEntries; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%d,%s\n",
            logArray[i].entryNo,
            logArray[i].sensorNo,
            logArray[i].temperature,
            logArray[i].humidity,
            logArray[i].light,
            logArray[i].time);
    }

    fclose(file);
    free(logArray);

    printf("Sorting completed. Sorted data saved in sorted_data.csv\n");

    return 0;
}
