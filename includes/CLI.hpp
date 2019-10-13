#ifndef CLI_HPP
# define CLI_HPP

#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "HostnameModule.hpp"
#include "UsernameModule.hpp"
#include "OSVersionModule.hpp"
#include "DateTimeModule.hpp"
#include "UsageCPUModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "NetworkModule.hpp"
# include <ncurses.h>
# include <iostream>

class CLI : public IMonitorDisplay{

public:

	CLI();
	virtual ~CLI();
	CLI & operator=(CLI const &rhs);
	CLI(CLI const &obj);

	void	mainloop();
	void	events();
	void	update();
	void	render();
	std::string		getModuleStringData(Data *d);

private:
	int			_y;
	int			_x;
	//WINDOW		*window;
	bool			flagRunning;
	bool			flagUsername;
	bool			flagOS;
	bool			flagTime;
	bool			flagCPU;
	bool			flagRAM;
	bool			flagNetwork;
	UsernameModule 	usernameMod; 	//text
	HostnameModule 	hostNameMod;	//text
	OSVersionModule OSMod;			//text
	DateTimeModule 	timeMod;		//text
	UsageCPUModule	usageCPUMod;	//plot + text
	CPUModule		CPUMod;			//text
	RAMModule		RAMMod;			//text
	NetworkModule	networkMod;		//text


};

#endif