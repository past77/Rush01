	
#include "UsernameModule.hpp"

	UsernameModule::UsernameModule(): d(new Data()){}
	UsernameModule::~UsernameModule(){}
	UsernameModule & UsernameModule::operator=(UsernameModule const &rhs){
		if (this != &rhs)
		*this = rhs;
		return (*this);
	}
	UsernameModule::UsernameModule(UsernameModule const &src){*this = src;}

	std::string	UsernameModule::setData(){
		return getenv("USER");
	}

	
	Data *		UsernameModule::getData(void) {
		d->name = "Username";
		d->data = setData();
		return d;
	}
