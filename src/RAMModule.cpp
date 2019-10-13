#include "RAMModule.hpp"
#include "main.hpp"

RAMModule::RAMModule() : d(new Data()){
	d->data = setData();
}
RAMModule::~RAMModule(){}

RAMModule & RAMModule::operator=(RAMModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
RAMModule::RAMModule(RAMModule const &src){
	*this = src;
}

std::string	RAMModule::setData(){
	FILE *fp;
	char buf[256];
	std::string str;
	const std::string findStr = "Memory: ";

		fp = popen("/usr/sbin/system_profiler SPHardwareDataType", "r");
		while(fgets(buf, sizeof(buf)-1, fp) != NULL){
		str = buf;
		if (std::string::npos != str.find(findStr)){
			str = ltrim(str, findStr);
			std::cout << str;
		}
	}
	pclose(fp);
	return str;
}

Data *		RAMModule::getData(void){
	this->d->name = "Memory";
	return d;
}