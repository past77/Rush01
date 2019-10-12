#ifndef HOSTNAMEMODULE
# define HOSTNAMEMODULE

#include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule{

public:

	HostnameModule();
	virtual ~HostnameModule();
	HostnameModule & operator=(HostnameModule const &rhs);
	HostnameModule(HostnameModule const &obj);

	Data *		getData(void);

private:
	std::string	setData();
	Data *d;
};

#endif