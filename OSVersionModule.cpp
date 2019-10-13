#include "OSVersionModule.hpp"
#include "main.hpp"

OSVersionModule::OSVersionModule(): d(new Data()){
	d->data = setData();
}
OSVersionModule::~OSVersionModule(){}

OSVersionModule & OSVersionModule::operator=(OSVersionModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
OSVersionModule::OSVersionModule(OSVersionModule const &src){
	*this = src;
}


std::string	OSVersionModule::setData(){

	FILE *fp;
	char buf[256];
	std::string str;
	std::stringstream ss;
	std::string osName;

	fp = popen("sw_vers", "r");
	while (fgets(buf, sizeof(buf) - 1, fp) != NULL){
	str = buf;
	std::size_t pos = str.find("\t");
	osName = str.substr (pos + 1  );
	ss << "[ "<<rtrim(osName) << " ] ";
}
	std::string s = ss.str();
	pclose(fp);
	return s;
}

Data *		OSVersionModule::getData(void){
		d->name = "OS/version";
	return d;
}