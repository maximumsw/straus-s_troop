/*
Дан текстовый файл. Подсчитать количество строк в нем.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const char PATH[] = "data.txt";//относительный путь к файлу
    FILE* file;
    char c;
    int count = 1;


    if (fopen_s(&file, PATH, "r") == 0)
    {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\t' || c == '.' || c == '?') { // Проверяем на пробел, перенос строки, табуляцию и знаки пунктуации
                continue;
            }
            else if (c == '\n') {
                count++;
            }
        }
        fclose(file);
        cout << "count: " << count;
    }
    else
    {
        cout << "Ошибка при открытии файла\n";
    }
    return 0;
}