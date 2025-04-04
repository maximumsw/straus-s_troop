/*
��� ��������� ����. ���������� ���������� ����, ������������ � �������, ������� ������ ������������.
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
    char targetChar;
    int count = 0;
    bool isSpace = true; // �������� � �������������, ��� ����� ������ �������� ��� ������

    cout << "����� ������: ";
    cin >> targetChar;

    if (fopen_s(&file, PATH, "r") == 0)
    {
        while ((c = fgetc(file)) != EOF) {
            if (c == ' ' || c == '\n' || c == '\t' || c == '.' || c == '?') { // ��������� �� ������, ������� ������, ��������� � ����� ����������
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
        cout << endl << "��������� '" << targetChar << "': " << count << endl; // ������� ����� ���������� ���������
    }
    else
    {
        cout << "������ ��� �������� �����\n";
    }
    return 0;
}