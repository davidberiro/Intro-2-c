#include <stdio.h>
#ifndef LINE_HEADER
#define LINE_HEADER

#define MAX_LENGTH 150
#define MIN_VALUE 0.00001

typedef struct vector{
    double coordinates[MAX_LENGTH];
    int id;
};

double innerProduct(double* vector1, double* vector2);

double* sumVector(double* vector1, double* vector2);

double* scalarTimesVector(double scalar, double* vector);

int parseFile(char* filename);

#endif