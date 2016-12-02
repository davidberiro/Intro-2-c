#include <stdio.h>
#ifndef LINE_HEADER
#define LINE_HEADER

#define MAX_LENGTH 150
#define MIN_VALUE 0.00001
#define TAGGED 1
#define UNTAGGED -1

typedef struct {
    double coordinates[MAX_LENGTH];
    int id;
}Vector;

double innerProduct(Vector* vector1, Vector* vector2);

Vector* sumVector(Vector* vector1, Vector* vector2);

Vector* scalarTimesVector(double scalar, Vector* vector);

int parseFile(char* filename);

int checkVector(Vector* vector, Vector* trainingVector);

int parseLine(char* line, int dimension, Vector *newVector, Vector *trainingVector);


#endif