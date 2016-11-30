#include <stdio.h>
#include "MyString.h"

int main()
{
    printf("%d", countSubStr("abab", "aba", 0));
    return 0;

}

int findLength(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
     length++;
    }
    return length;
}


unsigned int countSubStr(const char* str1, const char* str2, int isCyclic)
{
    int length1 = findLength(str1);
    int length2 = findLength(str2);
    int counter = 0;

    if (!isCyclic)
    {
        for (int i = 0; i < (length1-length2 + 1); i++)
        {
            int temp = 0;
            for (int j = 0; j < length2; j++)
            {
                if (str2[j] == str1[i+j])
                {
                    temp++;
                }
            }
            if (temp == length2)
            {
                counter++;
            }
        }
    }

    else
    {
        for (int i = 0; i < length1; i++)
        {
            int temp = 0;
            for (int j = 0; j < length2; j++)
            {
                if (str2[j] == str1[(i+j)%length1])
                {
                    temp++;
                }
            }
            if (temp == length2)
            {
                counter++;
            }
        }
    }
    return counter;
}