/*
��� ��������� ����. ���������� ���������� �������� � ���.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const char PATH[] = "data.txt";//������������� ���� � �����
    FILE* file;
    char c;
    int count = 0;


    if (fopen_s(&file, PATH, "r") == 0)
    {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') { // ��������� �� ������, ������� ������, ��������� � ����� ����������
                continue;
            }
                ++count;
        }
        fclose(file);
        cout << "count: " << count;
    }
    else
    {
        cout << "������ ��� �������� �����\n";
    }
    return 0;
}