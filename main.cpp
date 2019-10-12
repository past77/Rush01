#include "IMonitorModule.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OSVersionModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"

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
	std::cout << d->name << std::endl;

	DateTimeModule dtm;
	d = dtm.getData();
	std::cout << d->data ;

	CPUModule cpu;
	d = cpu.getData();
	std::cout << d->data;

}