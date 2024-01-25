#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {
	int command, number1, number2;

	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	cout.setf(ios_base::fixed);
	cout.precision(2);

	cout << "Функции калькулятора :\n\
		\r________________________\n\
		\r  1.Сложение\n\
		\r  2.Вычитание\n\
		\r  3.Умножение\n\
		\r  4.Деление\n\
		\r  5.Возведение в степень\n\
		\r  6.Нахождения квадратного корня\n\
		\r  7.Нахождение 1 процента от числа\n\
		\r  8.Найти факториал числа\n\
		\r  9.Выйти из программы\n\
		\r________________________\n";

	do {
		
		cout << "Введите номер команды: ";
		cin >> command;

		if (command <= 5) {
			cout << "Введите первое число (a): ";
			cin >> number1;
			cout << "Введите второе число (b): ";
			cin >> number2;
		}
		else if (5<command && command<9){
			cout << "Введите число: ";
			cin >> number1;
		}

		switch (command) {
		case 1: { cout << number1 <<" + " << number2  << " = " << number1 + number2 << endl; break; }
		case 2: { cout << number1 << " - " << number2 << " = " << number1 - number2 << endl; break; }
		case 3: { cout << number1 << " * " << number2 << " = " << number1 * number2 << endl; break; }
		case 4: { 
			if (number2 == 0) {
				cout << "Деление на ноль запрещено!" << endl;
				break;
			}
			cout << number1 << " / " << number2 << " = " << double(number1 / number2) << endl;
			break; 
		}
		case 5: { cout << number1 << " ^ " << number2 << " = " << pow(number1, number2) << endl; break; }
		case 6: { 
			if (number1 < 0) {
				cout << "Корень из отрицательного числа запрещен!" << endl;
				break;
			}
			cout << "sqrt(" << number1 << ") = " << sqrt(number1) << endl; 
			break; 
		}
		case 7: { cout << "1% out of " << number1 << " = " << double(number1 / 100) << endl; break; }
		case 8: {

			int factr = 1;
			for (int i = 1; i <= abs(number1); ++i) {
				factr *= i;
				}
			cout << abs(number1) << "! = " << factr << endl;
			}
		}


	} 
	while (command != 9);

	cout << "Выход из программы.";

	return 0;
}
