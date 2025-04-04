//#include <iostream>
//using namespace std;
//
//
//void check_A(double* variable) {
//    double a = *variable + *variable;
//
//    double* stipulation_1 = new double[pow(a,2)];
//    cout << *stipulation_1;
//}
//
//int main() {
//    double a;
//    double* variable = &a;
//    cin >> a;
//
//    check_A(variable);
//
//    return 0;
//}





#include <iostream>
#include <locale>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "ukr");
	int R0, R1, R2, R3;
	string res;

	cout << "Введіть опору 1: " << endl;
	cin >> R1;
	cout << "Введіть опору 2: " << endl;
	cin >> R2;
	cout << "Введіть опору 3: " << endl;
	cin >> R3;

	R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);

	cout << R0;

}
