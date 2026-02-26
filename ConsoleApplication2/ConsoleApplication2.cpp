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

    while (getchar() != '\n');

    inputFile = fopen(fileName, "r");
    if (inputFile == NULL)
    {
        printf("Ошибка: Не удалось открыть файл \"%s\"\n", fileName);
        printf("Нажмите любую клавишу для выхода...");
        getchar();
        return -1;
    }

    char tempFileName[MAX_FILENAME_LENGTH + 6];
    sprintf(tempFileName, "temp_%s", fileName);

    tempFile = fopen(tempFileName, "w");
    if (tempFile == NULL)
    {
        printf("Ошибка: Не удалось создать временный файл!\n");
        fclose(inputFile);
        printf("Нажмите любую клавишу для выхода...");
        getchar();
        return -1;
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL)
    {
        int len = strlen(line);

        if (len > 0 && line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
            len--;
        }

        char newLine[MAX_LINE_LENGTH] = "";
        int newLineIndex = 0;

        for (int i = 0; i < len; i++)
        {
            if (line[i] == symbol)
            {
                removalCount++;
            }
            else
            {
                newLine[newLineIndex++] = line[i];
            }
        }
        newLine[newLineIndex] = '\0';

        fprintf(tempFile, "%s\n", newLine);

        if (ferror(tempFile))
        {
            printf("Ошибка: Не удалось записать во временный файл!\n");
            fclose(inputFile);
            fclose(tempFile);
            printf("Нажмите любую клавишу для выхода...");
            getchar();
            return -1;
        }
    }
    fclose(inputFile);
    fclose(tempFile);

    if (remove(fileName) != 0)
    {
        printf("Ошибка: Не удалось удалить исходный файл!\n");
        printf("Нажмите любую клавишу для выхода...");
        getchar();
        return -1;
    }
    
    if (rename(tempFileName, fileName) != 0)
    {
        printf("Ошибка: Не удалось переименовать временный файл!\n");
        printf("Нажмите любую клавишу для выхода...");
        getchar();
        return -1;
    }
    printf("Готово! Удалено символов: %d\n", removalCount);
    printf("Нажмите любую клавишу для выхода...");
    getchar();

    return 0;
    
    

   
    
}