#include "RAMModule.hpp"
#include "main.hpp"

RAMModule::RAMModule() : d(new Data()){
	d->data = setData();
}
RAMModule::~RAMModule()
{
	if (d)
		delete d;
}

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
	std::stringstream ss;
	const std::string findStr = "Memory: ";

		fp = popen("/usr/sbin/system_profiler SPHardwareDataType", "r");
		while(fgets(buf, sizeof(buf)-1, fp) != NULL){
		str = buf;
			if (std::string::npos != str.find(findStr)){
				str = ltrim(str, findStr);
				ss<< rtrim(str)<< "/";
			}
		}
		fp = popen("top -l 1 -s 0 | grep PhysMem", "r");
		fgets(buf, sizeof(buf)-1, fp);
		str = buf;
				str = ltrim(str, "PhysMem: ");
				ss << rtrim(str);

	pclose(fp);
	return ss.str();
}

Data *		RAMModule::getData(void){
	this->d->name = "Memory";
	return d;
}