#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "IMonitorModule.hpp"

class CPUModule : public IMonitorModule{

public:

	CPUModule();
	virtual ~CPUModule();
	CPUModule & operator=(CPUModule const &rhs);
	CPUModule(CPUModule const &obj);

	Data *		getData(void);

private:
	std::string	setData();
	Data *d;
};

#endif