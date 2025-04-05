#pragma once

#include <iostream>

#include "MyInformations.h";

#include "GetInfos.h";

using namespace std;

namespace Fill
{

	Information::information infos;

    void fillInformation() {
        infos.Name = GetInfos::Name();
        infos.Age = GetInfos::Age();
        infos.Country = GetInfos::Country();
        infos.City = GetInfos::City();
        infos.MSalary = GetInfos::MSalary();

    };

}