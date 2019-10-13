#ifndef KotikModule_HPP
# define KotikModule_HPP

#include "IMonitorModule.hpp"
#include "main.hpp"
class KotikModule : public IMonitorModule{

public:
	KotikModule();
	virtual ~KotikModule();
	KotikModule & operator=(KotikModule const &rhs);
	KotikModule(KotikModule const &obj);

	Data *		getData(void);
	std::string getCatPart();
private:

	std::string	setData();
	std::string catArray[7];
	std::string catClip[4];

	Data *d;
};

#endif