#include "CPUModule.hpp"

CPUModule::CPUModule() : d(new Data()){}
CPUModule::~CPUModule(){}

CPUModule & CPUModule::operator=(CPUModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
CPUModule::CPUModule(CPUModule const &src){
	*this = src;
}


std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of("\n\r\t\f\v");
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
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
	fp = popen("getconf _NPROCESSORS_ONLN", "r");
	fgets(buf, sizeof(buf)-1, fp);
	str = buf;
	ss << "/Cores: "<< str;
	std::string s = ss.str();

	return s;
}

Data *		CPUModule::getData(void){
	this->d->name = "CPU Model/Cores";
	d->data = setData();
	return d;
}