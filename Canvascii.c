#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 40
#define MAX_WIDTH 80
void print_usage() {
    printf("Usage: ./canvascii [-n HEIGHT,WIDTH] [-s] [-k] [-p CHAR]\n");
    printf("[-h ROW] [-v COL] [-r ROW,COL,HEIGHT,WIDTH]\n");
    printf("[-l ROW1,COL1,ROW2,COL2] [-c ROW,COL,RADIUS]\n");
    printf("Draws on an ASCII canvas. The canvas is provided on stdin and\n");
    printf("the result is printed on stdout. The dimensions of the canvas\n");
    printf("are limited to at most 40 rows and at most 80 columns.\n");
    printf("\nIf no argument is provided, the program prints this help and exit.");
}


void drawCircle(int radius) {
    int x, y;
    for (y = -radius; y <= radius; y++) {
        for (x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawRectangle(int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            printf(".");
        }
        printf("\n");
    }
}

void drawHorizontalLine(int length) {
    int x;
    for (x = 0; x < length; x++) {
        printf(".");
    }
    printf("\n");
}

void drawVerticalLine(int length) {
    int y;
    for (y = 0; y < length; y++) {
        printf(".\n");
    }
}

int main() {
    int choice, width, height, length, radius;
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Horizontal Line\n");
    printf("4. Vertical Line\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the radius of the circle: ");
            scanf("%d", &radius);
            drawCircle(radius);
            break;
        case 2:
            printf("Enter the width of the rectangle: ");
            scanf("%d", &width);
            printf("Enter the height of the rectangle: ");
            scanf("%d", &height);
            drawRectangle(width, height);
            break;
        case 3:
            printf("Enter the length of the horizontal line: ");
            scanf("%d", &length);
            drawHorizontalLine(length);
            break;
        case 4:
            printf("Enter the length of the vertical line: ");
            scanf("%d", &length);
            drawVerticalLine(length);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}

