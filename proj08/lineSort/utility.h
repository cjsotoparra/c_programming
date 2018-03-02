#ifndef UTILITY_H
#define UTILITY_H

char **extendArray(char **oldArray, int oldLen, int newLen);


void sortArray (char **array, int len);

void printArray(char **lineArray, int len, char *str);

void freeArray(char **lineArray, int len);
#endif
