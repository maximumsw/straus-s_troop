/*
Дан массив строк. Записать их в файл, расположив каждый элемент массива 
на отдельной строке с сохранением порядка.
*/
#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 3;
	const int MAX_LENGTH = 255;
	char arrOfSymbol[SIZE][MAX_LENGTH] = { "First line", "Second line", "Third line" };
	const char PATH[] = "data.txt";
	FILE* file;
	char c;
	if (fopen_s(&file, PATH, "w") == 0)
	{
		for (int i = 0; i < SIZE; ++i)
		{
			fputs(arrOfSymbol[i], file);
			fputc('\n', file);
		}
		fclose(file);
	}
	else
		{
		cout << "Failed to open file for writing." << endl;
		}

	return 0;
}
