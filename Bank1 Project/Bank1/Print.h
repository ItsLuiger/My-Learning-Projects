#pragma once

#include <iostream>

#include "stFill.h";

using namespace std;

namespace Print
{

	void Print() {

		Fill::fillInformation();

		cout << "My Name is : " << Fill::infos.Name << endl;
		cout << "My Age is : " << Fill::infos.Age << endl;
		cout << "My Country is : " << Fill::infos.Country << endl;
		cout << "My City is : " << Fill::infos.City << endl;
		cout << "My MSalary is : " << Fill::infos.MSalary << endl;
	}

}