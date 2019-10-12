#ifndef DATETIMEMODULE
# define DATETIMEMODULE

#include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule{

public:

	DateTimeModule();
	virtual ~DateTimeModule();
	DateTimeModule & operator=(DateTimeModule const &rhs);
	DateTimeModule(DateTimeModule const &obj);

	Data *		getData(void);

private:
	std::string	setData();
	Data *d;
};

#endif