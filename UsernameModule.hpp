#ifndef USERNAMEMODULE
# define USERNAMEMODULE

#include "IMonitorModule.hpp"

class UsernameModule : public IMonitorModule{

public:
	UsernameModule();
	virtual ~UsernameModule();
	UsernameModule & operator=(UsernameModule const &rhs);
	UsernameModule(UsernameModule const &obj);

	Data *		getData(void);

private:
	std::string	setData();
	Data *d;
};

#endif