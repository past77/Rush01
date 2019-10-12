
#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : d(new Data()){}
HostnameModule::~HostnameModule(){}

HostnameModule & HostnameModule::operator=(HostnameModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
HostnameModule::HostnameModule(HostnameModule const &src){
	*this = src;
}

std::string	HostnameModule::setData(){
	char buf[256];
	size_t buflen = 256;
	gethostname(buf, buflen);
	return buf;
}

Data *		HostnameModule::getData(void){
	this->d->name = "Hostname";
	d->data = setData();
	return d;
}