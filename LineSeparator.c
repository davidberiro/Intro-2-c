#include "LineSeparator.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("too many arguments");
        return 1;
    }
    printf("hi");
    parseFile(argv[1]);
    return 1;


}

int parseFile(char* filename)
{
    printf("filename");
    FILE *fp = fopen(filename, "r");
    char line[MAX_LENGTH];
    int dim, trainingNumber;
    Vector *newVector = NULL;
    Vector *trainingVector = NULL;

    fgets(line, MAX_LENGTH, fp);
    strtok(line, "\n");
    dim = atoi(line);
    fgets(line, MAX_LENGTH, fp);
    strtok(line, "\n");
    trainingNumber = atoi(line);

    for (int i = 0; i < trainingNumber; i++)
    {
            fgets(line, MAX_LENGTH, fp);
            parseLine(line, dim, newVector, trainingVector);
    }

    return 1;


}

int parseLine(char* line, int dimension, Vector *newVector, Vector *trainingVector)
{
    const char COMMA[2] = ",";
    char *token;

    for (int i = 0; i < dimension; i++)
    {
        token = strtok(line, COMMA);
        newVector->coordinates[i] = atoi(token);
        printf("vector coordinate %d is %s", i+1, token);
    }
    token = strtok(line, COMMA);
    newVector->id = atoi(token);
    return 1;

}



Vector* scalarTimesVector(double scalar, Vector* vector)
{
    int i = 0;
    while (vector->coordinates[i] != '\0')
    {
        vector->coordinates[i] = vector->coordinates[i] * scalar;
        i++;
    }
    return vector;
}

double innerProduct(Vector* vector1, Vector* vector2)
{
    int i = 0;
    double prod = 0;

    while (vector1->coordinates[i] != '\0')
    {
        prod = prod + (vector1->coordinates[i]*vector2->coordinates[i]);
        i++;
    }
    return prod;
}

int checkVector(Vector* vector, Vector* trainingVector)
{
    if (innerProduct(vector, trainingVector) > MIN_VALUE)
    {
        return TAGGED;
    }
    return UNTAGGED;
}

Vector* sumVector(Vector* vector1, Vector* vector2)
{
    int i = 0;

    while (vector1->coordinates[i] != '\0')
    {
        vector1->coordinates[i] = vector1->coordinates[i] + vector2->coordinates[i];
        i++;
    }
    return vector1;
}
