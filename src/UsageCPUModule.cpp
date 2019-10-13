#include "UsageCPUModule.hpp"
#include "main.hpp"
UsageCPUModule::UsageCPUModule() : d(new Data()){}
UsageCPUModule::~UsageCPUModule(){}

UsageCPUModule & UsageCPUModule::operator=(UsageCPUModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
UsageCPUModule::UsageCPUModule(UsageCPUModule const &src){
	*this = src;
}


float UsageCPUModule::getUserData(){
	std::vector<std::string> res;

	res = vecSplit(d->data);
	this->user = stof(res.at(0));

	return this->user;
}

float UsageCPUModule::getSysData(){
	std::vector<std::string> res;

	res = vecSplit(d->data);
	this->sys = stof(res.at(2));

	return this->sys;
	}


float UsageCPUModule::getIdleData(){
	std::vector<std::string> res;

	res = vecSplit(d->data);
	this->idle = stof(res.at(4));

	return this->idle;
	}


std::string	UsageCPUModule::setData(){
	FILE *fp;
	char buf[256];
	std::string str;
	const std::string findStr = "CPU usage: ";



	fp = popen("top ", "r");
	while(fgets(buf, sizeof(buf)-1, fp) != NULL){
	str = buf;
	if (std::string::npos != str.find(findStr))
	{
		str = ltrim(str, findStr);
		return str;
	}
	}
	return NULL;
}

Data *		UsageCPUModule::getData(void){
	this->d->name = "Usage CPU";
	d->data = setData();
	return d;
}