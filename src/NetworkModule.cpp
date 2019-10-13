#include "NetworkModule.hpp"
#include "main.hpp"

NetworkModule::NetworkModule(): d(new Data()){
}
NetworkModule::~NetworkModule()
{
	if (d)
		delete d;
}

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
	const std::string findStr = "Networks: packets:";

		fp = popen("top -l 1 -n 0 | grep \"Networks:\"", "r");
		fgets(buf, sizeof(buf)-1, fp);
		str = buf;
		str = ltrim(str, findStr);
		std::cout << str;
	pclose(fp);
	return str;
}


Data *		NetworkModule::getData(void){
		d->name = "Network throughput";
		d->data = setData();
	return d;
}