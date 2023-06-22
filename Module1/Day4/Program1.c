#include <stdio.h>

// Structure for representing a box
struct Box {
    float length;
    float width;
    float height;
};

int main() {
    struct Box box;
    struct Box* boxPtr = &box;

    (*boxPtr).length = 2.5;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 4.2;

    boxPtr->length = 2.5;
    boxPtr->width = 3.0;
    boxPtr->height = 4.2;

    float volume = boxPtr->length * boxPtr->width * boxPtr->height;
    float surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->width * boxPtr->height + boxPtr->height * boxPtr->length);

    printf("Volume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);

    return 0;
}
