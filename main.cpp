#include "IMonitorModule.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OSVersionModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "UsageCPUModule.hpp"
#include "RAMModule.hpp"
#include "main.hpp"


std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of("\n\r\t\f\v");
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string ltrim(const std::string& s,const std::string findStr) {
	size_t start = s.find_first_not_of(findStr);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::vector<std::string> vecSplit(std::string str){

	std::istringstream iss(str);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());

	return results;
}

int main(){
	Data *d;

	UsernameModule imd;
	d = imd.getData();
	std::cout << d->data<< std::endl;

	OSVersionModule osv;
	d = osv.getData();
	std::cout << d->data << std::endl;

	HostnameModule htm;
	d = htm.getData();
	std::cout << d->data << std::endl;

	DateTimeModule dtm;
	d = dtm.getData();
	std::cout << d->data ;

	CPUModule cpu;
	d = cpu.getData();
	std::cout << d->data;


	UsageCPUModule ucpu;
	d = ucpu.getData();
	std::cout << ucpu.getUserData()<<" "<< ucpu.getIdleData() << " " << ucpu.getSysData() <<std::endl;
	std::cout << d->data;

	RAMModule ram;
	d = ram.getData();
	std::cout << d->data;


}