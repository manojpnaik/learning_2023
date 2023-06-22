#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

void convertToUpperCase(char *buffer) {
    while (*buffer) {
        *buffer = toupper((unsigned char)*buffer);
        buffer++;
    }
}

void convertToLowerCase(char *buffer) {
    while (*buffer) {
        *buffer = tolower((unsigned char)*buffer);
        buffer++;
    }
}

void convertToSentenceCase(char *buffer) {
    int capitalize = 1;
    while (*buffer) {
        if (capitalize && isalpha((unsigned char)*buffer))
            *buffer = toupper((unsigned char)*buffer);
        else
            *buffer = tolower((unsigned char)*buffer);

        capitalize = isspace((unsigned char)*buffer) || *buffer == '.' || *buffer == '!' || *buffer == '?';
        buffer++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <target_file>\n");
        printf("Options:\n");
        printf("  -u : Convert content to uppercase\n");
        printf("  -l : Convert content to lowercase\n");
        printf("  -s : Convert content to sentence case\n");
        return 1;
    }

    char *option = argv[1];
    char *sourcePath = argv[2];
    char *targetPath = argv[3];

    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE *targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (strcmp(option, "-u") == 0) {
            convertToUpperCase(buffer);
        } else if (strcmp(option, "-l") == 0) {
            convertToLowerCase(buffer);
        } else if (strcmp(option, "-s") == 0) {
            convertToSentenceCase(buffer);
        }

        fwrite(buffer, 1, bytesRead, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}
