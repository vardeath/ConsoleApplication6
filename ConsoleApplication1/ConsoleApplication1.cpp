#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include <functional>
#include<iomanip>
#include "windows.h"
//#include "../../std_lib_facilities.h"

using namespace std;

constexpr double m_to_cm = 100;
constexpr double in_to_cm = 2.54;
constexpr double ft_to_in = 12;
double val_max = 0;
double val_min = 0;
int i = 0;

double translate(double x, string y) {
	if (y == "cm") {
		x = x / m_to_cm;
		return (x);
	}
	else if (y == "in") {
		x = (x * in_to_cm) / m_to_cm;
		return (x);
	}
	else if (y == "ft") {
		x = (x * ft_to_in * in_to_cm) / m_to_cm;
		return (x);
	}
	else if (y == "ft") {
		x = (x * ft_to_in * in_to_cm) / m_to_cm;
		return (x);
	}
}
double solver(double x) {
	// случай 1
	if (i == 0) {
		cout << "наибольшее значение cреди введенных" << endl;
		//cout << "минимальное значение: " << val_min << endl;
		//cout << "случай 1" << endl;
		val_max = x;
		i = 1;
	}
	// случай 2
	else if (x > val_max && i == 1) {
		cout << "наибольшее значение cреди введенных" << endl;
		val_min = val_max;
		//cout << "минимальное значение: " << val_min << endl;
		//cout << "случай 2" << endl;
		val_max = x;
		i = 2;
	}
	// случай 3
	else if (x > val_max) {
		cout << "наибольшее значение cреди введенных" << endl;
		//cout << "минимальное значение: " << val_min << endl;
		//cout << "случай 3" << endl;
		val_max = x;
	}
	// случай 4
	else if (x < val_max && i == 1) {
		cout << "наименьшее значение cреди введенных" << endl;
		val_min = x;
		//cout << "минимальное значение: " << val_min << endl;
		//cout << "случай 4" << endl;
		i = 2;
	}
	// случай 5
	else if (x < val_min) {
		cout << "наименьшее значение cреди введенных" << endl;
		val_min = x;
		//cout << "минимальное значение: " << val_min << endl;
		//cout << "случай 5" << endl;
	}
	return(x);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name = "";
	double var1;
	double sum = 0;
	int schet = 0;
	vector<double> my_array;
	cout << "Введите число и единицу измерения (допускаются: cm - сантиметры, in - дюймы, ft - футы):" << endl;
	while (cin >> var1 >> name) {
		if (name == "cm" || name == "in" || name == "ft") {
			double var2 = translate(var1, name);
			cout << "вы ввели число: " << var2 << "m" << endl;
			//cout << "случай 0" << endl;
			solver(var2);
			sum = sum + var2;
			++schet;
			my_array.push_back(var2);
		}
		else {
			cout << "недопустимая единица измерения" << endl;
		}
	}
	sort(my_array.begin(), my_array.end());
	cout << "Вывод введенных чисел в порядке возрастания: "<< endl;
	for (int x = 0; x < my_array.size(); ++x) {
		cout << x << ". " << my_array[x] << "m" << endl;
	}
	cout << "Сумма всех введенных чисел: " << sum << "m" << endl;
	cout << "Количество итераций: " << schet << endl;
	system("pause");
}
 
