#ifndef NetworkModule_HPP
# define NetworkModule_HPP

#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule{

public:
	NetworkModule();
	virtual ~NetworkModule();
	NetworkModule & operator=(NetworkModule const &rhs);
	NetworkModule(NetworkModule const &obj);

	Data *		getData(void);
	std::string rtrim(const std::string& s);

private:
	std::string	setData();
	Data *d;
};

#endif