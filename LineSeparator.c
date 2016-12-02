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
    parseFile(argv[1]);
    return 1;


}

int parseFile(char* filename)
{
    printf("filename");
    FILE *fp = fopen(filename, "r");
    char line[MAX_LENGTH];
    int dim, trainingNumber;

    fgets(line, MAX_LENGTH, fp);
    strtok(line, "\n");
    dim = atoi(line);
    fgets(line, MAX_LENGTH, fp);
    strtok(line, "\n");
    trainingNumber = atoi(line);

    for (int i = 0; i < trainingNumber; i++)
    {
            fgets(line, MAX_LENGTH, fp);
            parseLine(line);
    }

    return 1;


}

int parseLine(char* line, int dimension)
{
    vector trainingVector;
}



double* scalarTimesVector(double scalar, double* vector)
{
    int i = 0;
    double* prod= NULL;
    while (vector[i] != '\0')
    {
        prod[i] = vector[i] * scalar;
        i++;
    }
    return prod;
}

double innerProduct(double* vector1, double* vector2)
{
    int i = 0;
    double prod = 0;

    while (vector1[i] != '\0')
    {
        prod = prod + (vector1[i]*vector2[i]);
        i++;
    }
    return prod;
}

double* sumVector(double* vector1, double* vector2)
{
    int i = 0;
    double* result = NULL;

    while (vector1[i] != '\0')
    {
        result[i] = vector1[i] + vector2[i];
        i++;
    }
    return result;
}
