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
	// ������ 1
	if (i == 0) {
		cout << "���������� �������� c���� ���������" << endl;
		//cout << "����������� ��������: " << val_min << endl;
		//cout << "������ 1" << endl;
		val_max = x;
		i = 1;
	}
	// ������ 2
	else if (x > val_max && i == 1) {
		cout << "���������� �������� c���� ���������" << endl;
		val_min = val_max;
		//cout << "����������� ��������: " << val_min << endl;
		//cout << "������ 2" << endl;
		val_max = x;
		i = 2;
	}
	// ������ 3
	else if (x > val_max) {
		cout << "���������� �������� c���� ���������" << endl;
		//cout << "����������� ��������: " << val_min << endl;
		//cout << "������ 3" << endl;
		val_max = x;
	}
	// ������ 4
	else if (x < val_max && i == 1) {
		cout << "���������� �������� c���� ���������" << endl;
		val_min = x;
		//cout << "����������� ��������: " << val_min << endl;
		//cout << "������ 4" << endl;
		i = 2;
	}
	// ������ 5
	else if (x < val_min) {
		cout << "���������� �������� c���� ���������" << endl;
		val_min = x;
		//cout << "����������� ��������: " << val_min << endl;
		//cout << "������ 5" << endl;
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
	cout << "������� ����� � ������� ��������� (�����������: cm - ����������, in - �����, ft - ����):" << endl;
	while (cin >> var1 >> name) {
		if (name == "cm" || name == "in" || name == "ft") {
			double var2 = translate(var1, name);
			cout << "�� ����� �����: " << var2 << "m" << endl;
			//cout << "������ 0" << endl;
			solver(var2);
			sum = sum + var2;
			++schet;
			my_array.push_back(var2);
		}
		else {
			cout << "������������ ������� ���������" << endl;
		}
	}
	sort(my_array.begin(), my_array.end());
	cout << "����� ��������� ����� � ������� �����������: "<< endl;
	for (int x = 0; x < my_array.size(); ++x) {
		cout << x << ". " << my_array[x] << "m" << endl;
	}
	cout << "����� ���� ��������� �����: " << sum << "m" << endl;
	cout << "���������� ��������: " << schet << endl;
	system("pause");
}
 
