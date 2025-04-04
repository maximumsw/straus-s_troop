/*
Дан текстовый файл. Подсчитать количество символов в нем.
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
    int count = 0;


    if (fopen_s(&file, PATH, "r") == 0)
    {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') { // Проверяем на пробел, перенос строки, табуляцию и знаки пунктуации
                continue;
            }
                ++count;
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