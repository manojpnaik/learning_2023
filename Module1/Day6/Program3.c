#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

LogEntry logArray[MAX_ENTRIES];
int numEntries = 0;

void readDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Read and discard the header line

    while (fgets(line, sizeof(line), file)) {
        if (numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries exceeded.\n");
            break;
        }

        char* token = strtok(line, ",");
        logArray[numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logArray[numEntries].sensorNo, token, sizeof(logArray[numEntries].sensorNo));

        token = strtok(NULL, ",");
        logArray[numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        logArray[numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        logArray[numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(logArray[numEntries].time, token, sizeof(logArray[numEntries].time));

        numEntries++;
    }

    fclose(file);
}

void displayLogEntries() {
    if (numEntries == 0) {
        printf("No log entries found.\n");
        return;
    }

    printf("Log Entries:\n");
    printf("--------------------------------------------------------------------\n");
    printf("EntryNo   SensorNo   Temperature   Humidity   Light   Time\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%-9d %-10s %-13.2f %-9d %-8d %s\n",
               logArray[i].entryNo,
               logArray[i].sensorNo,
               logArray[i].temperature,
               logArray[i].humidity,
               logArray[i].light,
               logArray[i].time);
    }

    printf("--------------------------------------------------------------------\n");
}

int main() {
    readDataFromFile("data.csv");
    displayLogEntries();

    return 0;
}
