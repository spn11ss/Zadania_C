#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME_LENGTH 256

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    char fileName[MAX_FILENAME_LENGTH];
    char symbol;
    FILE* inputFile, * tempFile;
    char line[MAX_LINE_LENGTH];
    int removalCount = 0;


    printf("Введите имя файла: ");
    fgets(fileName, MAX_FILENAME_LENGTH, stdin);

    fileName[strcspn(fileName, "\n")] = 0;

    printf("Введите символ для удаления: ");
    scanf("%c", &symbol);

    
    
}