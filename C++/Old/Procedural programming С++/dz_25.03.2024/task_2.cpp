/*
��� ��������� ����. ���������� � ������ ���� ��� ��� ������ � ������� � ��� ������� 0 �� ������ 1 � ��������..
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const char firstPATH[] = "firstData.txt"; 
    const char secondPATH[] = "secondData.txt";
    FILE* firstfile;
    FILE* secondFile;
    int c; 

    if (fopen_s(&firstfile, firstPATH, "r") == 0 && fopen_s(&secondFile, secondPATH, "w") == 0)
    {
        while ((c = fgetc(firstfile)) != EOF) {
            if (c == '0') {
                c = '1'; 
            }
            else if (c == '1') {
                c = '0'; 
            }
            fputc(c, secondFile); 
        }
        fclose(firstfile);
        fclose(secondFile);
    }
    else
    {
        cout << "������ ��� �������� �����\n";
    }
    return 0;
}