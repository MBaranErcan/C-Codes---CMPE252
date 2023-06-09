#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_SHAPES 50

/* type definitions come here */
typedef struct {
    double x;
    double y;
    double z;
}point_t;   // Point_t

typedef struct {
    point_t center;
    double radius;
}sphere_t;  // Sphere_t
typedef struct {
    point_t center;
    double side;
}cube_t;    // Cube_t
typedef struct {
    point_t center;
    double base_side_length;
    double height;
}square_prism_t;// Square_prism_t

typedef struct {
    sphere_t sphere;
    square_prism_t square_prism;
    cube_t cube;
}shape3d_data_t;    // Shape3d_data_t

typedef enum {
    CUBE,
    SQUARE_PRISM,
    SPHERE
} class_t;      // Class_t

typedef struct{
    class_t type;
    shape3d_data_t shape;
}shape_t;   // Shape_t

/* function prototypes*/
int scanShape(FILE *filep, shape_t *objp);
int loadShapes(shape_t shapes[]);
void printShape(const shape_t *objp);

int main()
{
    shape_t shapes[MAX_SHAPES];
    int numOfShapes = loadShapes(shapes);

    printf("\nShapes 3D:\n");   // Fixed it.
    for (int i = 0; i < numOfShapes; i++)
        printShape(&shapes[i]);

    return 0;
}
int scanShape(FILE *filep, shape_t *objp) {
    char shape[20];
    int result;
    result = fscanf(filep, "%s", shape);
    if (result == EOF) {
        return 0;
    }
    if (strcasecmp(shape, "CUBE") == 0) {
        objp->type = CUBE;
        result = fscanf(filep, "%lf%lf%lf%lf" , &objp->shape.cube.center.x, &objp->shape.cube.center.y, &objp->shape.cube.center.z, &objp->shape.cube.side);
        if (result != 4)
            return 0;
    }
    else if (strcasecmp(shape, "SQUARE_PRISM") == 0) {
        objp->type = SQUARE_PRISM;
        result = fscanf(filep, "%lf%lf%lf%lf%lf", &objp->shape.square_prism.center.x, &objp->shape.square_prism.center.y, &objp->shape.square_prism.center.z, &objp->shape.square_prism.base_side_length, &objp->shape.square_prism.height);
        if (result != 5)
            return 0;
    }
    else if (strcasecmp(shape, "SPHERE") == 0) {
        objp->type = SPHERE;
        result = fscanf(filep, "%lf%lf%lf%lf", &objp->shape.sphere.center.x, &objp->shape.sphere.center.y, &objp->shape.sphere.center.z, &objp->shape.sphere.radius);
        if (result != 4)
            return 0;
    }
    else {
            return 0;
        }
    return 1;
}

int loadShapes (shape_t shapes[]) {
    char filename[100];
    printf("Enter the file name to read: ");
    scanf("%s", filename);
    FILE *filep = fopen(filename, "r");
    if (filep == NULL) {
        printf("Error opening file!");
        return 0;
    }
    printf("Opening %s\n", filename);
    int shape_count = 0;
    while (scanShape(filep, &shapes[shape_count])) {
        shape_count++;
    }
    printf("Loading complete\n");
    printf("Closing %s\n", filename);
    fclose(filep);
    return shape_count;
}

void printShape(const shape_t *objp) {
    if (objp->type == CUBE) {
        double volume = pow(objp->shape.cube.side, 3);
        printf("Cube: <%.2lf %.2lf %.2lf> <%.2lf> <%.2lf>\n", objp->shape.cube.center.x, objp->shape.cube.center.y, objp->shape.cube.center.z, objp->shape.cube.side, volume);
    }
    if (objp->type == SQUARE_PRISM) {
        double volume = (pow(objp->shape.square_prism.base_side_length,2) * objp->shape.square_prism.height);
        printf("Square_prism: <%.2lf %.2lf %.2lf> <%.2lf %.2lf> <%.2lf>\n", objp->shape.square_prism.center.x, objp->shape.square_prism.center.y, objp->shape.square_prism.center.z, objp->shape.square_prism.base_side_length, objp->shape.square_prism.height, volume);
    }
    if (objp->type == SPHERE) {
        double volume = (4.0/3.0) * M_PI * pow(objp->shape.sphere.radius, 3); 
        printf("Sphere: <%.2lf %.2lf %.2lf> <%.2lf> <%.2lf>\n", objp->shape.sphere.center.x, objp->shape.sphere.center.y, objp->shape.sphere.center.z, objp->shape.sphere.radius, volume);
    }
}

