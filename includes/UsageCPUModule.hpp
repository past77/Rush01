#ifndef USAGECPUMODULE_HPP
# define USAGECPUMODULE_HPP

#include "IMonitorModule.hpp"

class UsageCPUModule : public IMonitorModule{

public:

	UsageCPUModule();
	virtual ~UsageCPUModule();
	UsageCPUModule & operator=(UsageCPUModule const &rhs);
	UsageCPUModule(UsageCPUModule const &obj);

	Data *		getData(void);
	float getUserData();
	float getSysData();
	float getIdleData();
	void	gatherUsage(float *arr);
	bool	isReadyForUpdate();
private:
	std::string	setData();
	float user;
	float sys;
	float idle;
	Data *d;
	unsigned long long lastUpdateTime;
};

#endif