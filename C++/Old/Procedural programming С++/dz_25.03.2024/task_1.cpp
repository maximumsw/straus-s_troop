/*
Дан текстовый файл. Подсчитать количество слов, начинающихся с символа, который задает пользователь.
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
    char targetChar;
    int count = 0;
    bool isSpace = true; // начинаем с предположения, что перед первым символом был пробел

    cout << "Какой символ: ";
    cin >> targetChar;

    if (fopen_s(&file, PATH, "r") == 0)
    {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') { // Проверяем на пробел, перенос строки, табуляцию и знаки пунктуации
                isSpace = true;
            }
            else if (c == targetChar && isSpace == true) {
                ++count;
                isSpace = false;
            }
            else {
                isSpace = false;
            }
        }
        fclose(file);
        cout << endl << "Вхождений '" << targetChar << "': " << count << endl; // Выводим общее количество вхождений
    }
    else
    {
        cout << "Ошибка при открытии файла\n";
    }
    return 0;
}