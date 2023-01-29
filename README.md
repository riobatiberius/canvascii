# canvascii
# use of program
This is a command-line program that draws ASCII art on a canvas with limited dimensions of 40 rows and 80 columns.The program prints usage information if no argument is provided or if the argument is invalid.
# How to compile it

# How to perform it
The code uses the printf function to print the usage information and the canvas, and the sscanf function to parse the values provided as options. The memset function is used to fill the canvas with a specific character, and the strcmp function is used to compare the options provided as arguments to determine which action to perform on the canvas.
# What are the input and output formats
It takes different arguments as input to perform different actions on the canvas like creating a new canvas, clearing the canvas, drawing a rectangle, a horizontal line, a vertical line, a filled rectangle, or a line. The result of these actions is displayed on the standard output.
# What are the cases of error managed?
The code has several options that you can provide as arguments to draw various shapes on the canvas, such as lines, rectangles, and characters. and it ignores the eroors and prints out the outputs
