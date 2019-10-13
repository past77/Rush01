#include "IMonitorModule.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OSVersionModule.hpp"
#include "DateTimeModule.hpp"
#include "CPUModule.hpp"
#include "UsageCPUModule.hpp"
#include "RAMModule.hpp"
#include "main.hpp"


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