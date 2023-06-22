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

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open file: data.csv\n");
        return 1;
    }

    LogEntry logArray[MAX_ENTRIES];
    int numEntries = 0;

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Read and discard the header line

    while (fgets(line, sizeof(line), file)) {
        if (numEntries >= MAX_ENTRIES) {
            printf("Maximum number of entries exceeded.\n");
            break;
        }

        sscanf(line, "%d,%[^,],%f,%d,%d,%s",
            &logArray[numEntries].entryNo,
            logArray[numEntries].sensorNo,
            &logArray[numEntries].temperature,
            &logArray[numEntries].humidity,
            &logArray[numEntries].light,
            logArray[numEntries].time);

        numEntries++;
    }

    fclose(file);

    int entryNoToDelete;
    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNoToDelete);

    int entryFound = 0;
    for (int i = 0; i < numEntries; i++) {
        if (logArray[i].entryNo == entryNoToDelete) {
            entryFound = 1;
            for (int j = i; j < numEntries - 1; j++) {
                logArray[j] = logArray[j + 1];
            }
            numEntries--;
            break;
        }
    }

    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to create file: data.csv\n");
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

    if (entryFound) {
        printf("Entry with EntryNo %d deleted successfully.\n", entryNoToDelete);
    } else {
        printf("Entry with EntryNo %d not found.\n", entryNoToDelete);
    }

    return 0;
}
