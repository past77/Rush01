#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <ctime>

struct Data 
{
	std::string name;
	std::string data;
};

class IMonitorModule
{
public:
	virtual ~IMonitorModule() = 0;
	virtual Data *		getData(void) = 0;

protected:
	virtual std::string setData() = 0;
};


#endif