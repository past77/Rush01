#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule() : d(new Data()){}
DateTimeModule::~DateTimeModule(){}

DateTimeModule & DateTimeModule::operator=(DateTimeModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
DateTimeModule::DateTimeModule(DateTimeModule const &src){
	*this = src;
}

std::string	DateTimeModule::setData(){
	 time_t now = time(0);

	std::string dt = ctime(&now);
	return dt;
}

Data *		DateTimeModule::getData(void){
	this->d->name = "Hostname";
	d->data = setData();
	return d;
}