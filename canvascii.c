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

void print_canvas(char canvas[MAX_HEIGHT][MAX_WIDTH], int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    char canvas[MAX_HEIGHT][MAX_WIDTH];
    int height, width;
    int i, j;

    if (argc == 1) {
        print_usage();
        return 0;
    }

    // parse arguments and perform actions on canvas
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            // -n: new canvas
            sscanf(argv[i+1], "%d,%d", &height, &width);
            for (j = 0; j < height; j++) {
                memset(canvas[j], '.', width);
            }
            i++;
        } else if (strcmp(argv[i], "-s") == 0) {
            // -s: clear canvas
            for (j = 0; j < height; j++) {
                memset(canvas[j], '.', width);
            }
        } else if (strcmp(argv[i], "-k") == 0) {
            // -k: draw rectangle
            for (j = 0; j < height; j++) {
                canvas[j][0] = '|';
                canvas[j][width-1] = '|';
            }
            for (j = 0; j < width; j++) {
                canvas[0][j] = '-';
                canvas[height-1][j] = '-';
            }
        } else if (strcmp(argv[i], "-p") == 0) {
            // -p: draw character
            char ch;
            sscanf(argv[i+1], "%c", &ch);
            for (j = 0; j < height; j++) {
                for (int k = 0; k < width; k++) {
                    canvas[j][k] = ch;
                }
            }
            i++;
        } else if (strcmp(argv[i], "-h") == 0) {
            // -h: draw horizontal line
            int row;
            char ch;
            sscanf(argv[i+1], "%d,%c", &row, &ch);
            for (j = 0; j < width; j++) {
                canvas[row][j] = ch;
            }
            i++;
        } else if (strcmp(argv[i], "-v") == 0) {
            // -v: draw vertical line
            int col;
            char ch;
            sscanf(argv[i+1], "%d,%c", &col, &ch);
            for (j = 0; j < height; j++) {
                canvas[j][col] = ch;
            }
            i++;
        } else if (strcmp(argv[i], "-r") == 0) {
            // -r: draw rectangle
            int row, col, rect_height, rect_width;
            char ch;
            sscanf(argv[i+1], "%d,%d,%d,%d,%c", &row, &col, &rect_height, &rect_width, &ch);
            for (j = 0; j < rect_height; j++) {
                for (int k = 0; k < rect_width; k++) {
                    canvas[row+j][col+k] = ch;
                }
            }
            i++;
        } else if (strcmp(argv[i], "-l") == 0) {
            // -l: draw line
            int row1, col1, row2, col2;
            char ch;
            sscanf(argv[i+1], "%d,%d,%d,%d,%c", &row1, &col1, &row2, &col2, &ch);
            if (row1 == row2) {
                // draw horizontal line
                for (j = col1; j <= col2; j++) {
                    canvas[row1][j] = ch;
                }
            } else if (col1 == col2) {
                // draw vertical line
                for (j = row1; j <= row2; j++) {
                    canvas[j][col1] = ch;
                }
            } else {
                // draw diagonal line
                for (j = row1; j <= row2; j++) {
                    canvas[j][j+col1-row1] = ch;
                }
            }
            i++;
        } else if (strcmp(argv[i], "-c") == 0) {
            // -c: draw circle
            int row, col, radius;
            char ch;
            sscanf(argv[i+1], "%d,%d,%d,%c", &row, &col, &radius, &ch);
            for (j = 0; j < height; j++) {
                for (int k = 0; k < width; k++) {
                    if ((j-row)*(j-row)+(k-col)*(k-col) <= radius*radius) {
                        canvas[j][k] = ch;
                    }
                }
            }
            i++;
        }
    }

    print_canvas(canvas, height, width);

    return 0;
}
