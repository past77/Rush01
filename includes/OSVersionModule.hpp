#ifndef OSVERSIONMODULE_HPP
# define OSVERSIONMODULE_HPP

#include "IMonitorModule.hpp"

class OSVersionModule : public IMonitorModule{

public:
	OSVersionModule();
	virtual ~OSVersionModule();
	OSVersionModule & operator=(OSVersionModule const &rhs);
	OSVersionModule(OSVersionModule const &obj);

	Data *		getData(void);

private:
	std::string	setData();
	Data *d;
};

#endif