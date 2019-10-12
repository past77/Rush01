#ifndef OSVERSIONMODULE
# define OSVERSIONMODULE

#include "IMonitorModule.hpp"

class OSVersionModule : public IMonitorModule{

public:
	OSVersionModule();
	virtual ~OSVersionModule();
	OSVersionModule & operator=(OSVersionModule const &rhs);
	OSVersionModule(OSVersionModule const &obj);

	Data *		getData(void);
	std::string rtrim(const std::string& s);

private:
	std::string	setData();
	Data *d;
};

#endif