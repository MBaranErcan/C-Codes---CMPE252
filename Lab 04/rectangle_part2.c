#include <stdio.h>
#include <string.h>

#define MAX_SHAPES 50

/* type definitions come here */
typedef struct {    // Point type def.
    double x;
    double y;
}point_t;

typedef struct {    // Rectangle type def.
    point_t left_corner;
    double width;
    double height;
    double perimeter;
}rectangle_t;

/* function prototypes*/
int scanShape(FILE *filep, rectangle_t *objp);
int loadRectangle(rectangle_t shapes[]);
void printShape(const rectangle_t *objp);
int isPerimeterBetween(const rectangle_t *objp, double minPerimeter, double maxPerimeter);
/* function prototypes*/

int main()
{
    rectangle_t shapes[MAX_SHAPES];
    int numOfShapes = loadRectangle(shapes);

    printf("\nRectangles:\n");
    for (int i = 0; i < numOfShapes; i++) {
        printf("Rectangle %d: ",i+1);
        printShape(&shapes[i]);
    }

    double minPerimeter, maxPerimeter;
    printf("\nEnter minimum perimeter: \n");
    scanf("%lf" ,&minPerimeter);
    printf("\nEnter maximum perimeter: \n");
    scanf("%lf" , &maxPerimeter);
    printf("\nThe following rectangles satisfy user conditions:\n");
    for (int i = 0; i < numOfShapes; i++) {
        if (isPerimeterBetween(&shapes[i],minPerimeter,maxPerimeter))
        {
            printf("Rectangle %d: ",i+1);
            printShape(&shapes[i]);
        }
    }
    return 0;
}

int scanShape(FILE *filep, rectangle_t *objp) {
    point_t point;
    double w, h;
    char shape_t[50];
    int result = fscanf(filep, "%s%lf%lf%lf%lf", shape_t, &point.x, &point.y, &w, &h); // Read the values from file
    if (result >= 1 && strcmp(shape_t, "rectangle") == 0) {     // If the shape is a rectangle.
        objp->left_corner.x = point.x - w/2;  // Set the x value of the left corner.
        objp->left_corner.y = point.y - h/2;  // Set the y value of the left corner.
        objp->width = w;                // Set the width.
        objp->height = h;               // Set the height.
        objp->perimeter = 2 * (w + h);  // Set the perimeter.
        return 1;
    }
    return 0;
}

int loadRectangle(rectangle_t shapes[]) {
    char filename[100];
    printf("Enter the file name to read: ");
    scanf("%s", filename);                      // Get filename.
    FILE *filep = fopen(filename, "r");
    if (filep == NULL) {                               // If failed to open.
        printf("Error opening file\n");
        return 0;
    }
    printf("Opening %s\n", filename);
    int i = 0;                                          // While we do not exceed the max size and until we reach to the end.
    while (i < MAX_SHAPES && scanShape(filep, &shapes[i])) {
        i++;
    }
    printf("Loading complete\n");                 // After, close the file.
    printf("Closing %s\n", filename);
    fclose(filep);
    return i;
}

void printShape(const rectangle_t *objp) {                                                                     // Print the:
    printf("<%.2lf %.2lf>", objp->left_corner.x, objp->left_corner.y );                                 // Bottom left corner.
    printf("<%.2lf %.2lf>", (objp->left_corner.x + objp->width), (objp->left_corner.y) );               // Bottom right corner.
    printf("<%.2lf %.2lf>", (objp->left_corner.x), (objp->left_corner.y + objp->height) );              // Upper left corner.
    printf("<%.2lf %.2lf>", (objp->left_corner.x + objp->width), (objp->left_corner.y + objp->height) );// Upper right corner.
    printf("P<%.2lf>\n", objp->perimeter);                                                              // Perimeter.
}


int isPerimeterBetween(const rectangle_t *objp, double minPerimeter, double maxPerimeter) {                     // If the given rectangle's parameter in between the min-max values
    if (minPerimeter <= objp->perimeter && objp->perimeter <= maxPerimeter)                                     // return 1; else return 0.
        return 1;
    return 0;
}