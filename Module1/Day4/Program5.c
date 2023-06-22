#include <stdio.h>

struct Point {
    int x;
    int y;
};

void swapP(struct Point* p1, struct Point* p2) {
    int temp = p1->x;
    p1->x = p2->x;
    p2->x = temp;

    temp = p1->y;
    p1->y = p2->y;
    p2->y = temp;
}

int main() {
    struct Point point1 = {1, 2};
    struct Point point2 = {3, 4};

    printf("Before swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    swapP(&point1, &point2);

    printf("\nAfter swapping:\n");
    printf("Point 1: (%d, %d)\n", point1.x, point1.y);
    printf("Point 2: (%d, %d)\n", point2.x, point2.y);

    return 0;
}
