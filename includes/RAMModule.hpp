#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "IMonitorModule.hpp"

class RAMModule : public IMonitorModule{

public:

	RAMModule();
	virtual ~RAMModule();
	RAMModule & operator=(RAMModule const &rhs);
	RAMModule(RAMModule const &obj);

	Data *		getData(void);

private:
	std::string	setData();
	Data *d;
};

#endif