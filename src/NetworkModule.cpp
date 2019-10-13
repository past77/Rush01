#include "NetworkModule.hpp"
#include "main.hpp"

NetworkModule::NetworkModule(): d(new Data()){
	d->data = setData();
}
NetworkModule::~NetworkModule(){}

NetworkModule & NetworkModule::operator=(NetworkModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
NetworkModule::NetworkModule(NetworkModule const &src){
	*this = src;
}


std::string	NetworkModule::setData(){

	FILE *fp;
	char buf[256];
	std::string str;
	const std::string findStr = "Memory: ";

		fp = popen("top -l 1 -n 0 | grep \"Networks:\"", "r");
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


Data *		NetworkModule::getData(void){
		d->name = "OS/version";
	return d;
}