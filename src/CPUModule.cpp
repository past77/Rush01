#include "CPUModule.hpp"
#include "main.hpp"

CPUModule::CPUModule() : d(new Data()){}
CPUModule::~CPUModule()
{
	if (d)
		delete d;
}

CPUModule & CPUModule::operator=(CPUModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
CPUModule::CPUModule(CPUModule const &src){
	*this = src;
}

std::string	CPUModule::setData(){
	FILE *fp;
	char buf[256];
	std::string str;
	std::stringstream ss;
	std::string osName;

	fp = popen("sysctl -a | grep brand", "r");
	fgets(buf, sizeof(buf)-1, fp);
	str = buf;
	std::size_t pos = str.find(" ");
	osName = str.substr (pos + 1  );
	ss << rtrim(osName) ;
	pclose(fp);
	fp = popen("getconf _NPROCESSORS_ONLN", "r");
	fgets(buf, sizeof(buf)-1, fp);
	str = buf;
	ss << "/Cores: "<< str;
	std::string s = ss.str();
	pclose(fp);
	return s;
}

Data *		CPUModule::getData(void){
	this->d->name = "CPU Model/Cores";
	d->data = setData();
	return d;
}