#pragma once

#include <iostream>

using namespace std;

namespace GetInfos
{

	string Name() {

		string Name;

		cout << "Enter Your Name : \n";
		cin >> Name;

		return Name;
	}
	int Age() {

		int Age;

		cout << "Enter Your Age : \n";
		cin >> Age;

		return Age;
	}
	string Country() {

		string Country;

		cout << "Enter Your Country : \n";
		cin >> Country;

		return Country;
	}

	string City() {

		string City;

		cout << "Enter Your City : \n";
		cin >> City;

		return City;
	}


	int MSalary() {

		int MSalary;

		cout << "Enter Your MSalary : \n";
		cin >> MSalary;

		return MSalary;
	}
}