#include "CLI.hpp"
#include <iostream>

CLI::CLI() : _y(50), _x(100), flagRunning(true), kotikFlag(false), flagUsername(true), flagOS(true),
flagTime(true), flagCPU(true), flagRAM(true), flagNetwork(true)
{
	initscr();
	nodelay(stdscr,true);
	keypad(stdscr,true);
	noecho();
	curs_set(0);   
	resizeterm(_y, _x);

	start_color();
	init_color(COLOR_MAGENTA, 230, 230, 230);
	init_pair(1, COLOR_GREEN, -1);
	wattron(stdscr, COLOR_PAIR(1));
	box(stdscr, 0, 0);
	wattroff(stdscr, COLOR_PAIR(1));
	refresh();
}

CLI::~CLI(){
	endwin();
}

CLI & CLI::operator=(CLI const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
CLI::CLI(CLI const &src){
	*this = src;
}

std::string		CLI::getModuleStringData(Data *d)
{
	std::string info = std::string(d->name + ": " + d->data);
	return (info);
}


	void	CLI::mainloop(){

	while (this->flagRunning)
	{
		events();
		update();
		render();
	}

}

	void	CLI::events(){
	int key = getch();

	switch(key) {
		case 49:
			flagUsername = !flagUsername;
			break;
		case 50:
			flagOS = !flagOS;
			break;
		case 51:
			flagTime = !flagTime;
			break;
		case 52:
			flagRAM = !flagRAM;
			break;
		case 53:
			flagCPU = !flagCPU;
			break;
		case 54:
			flagNetwork = !flagNetwork;
			break;
		case ' ':
			kotikFlag = !kotikFlag;
			break;
		case 27:
			flagRunning = false;
			break;
}
	}
	void	CLI::update(){

}

void	CLI::render()
{
	int iter;
	iter = 3;
	std::string		str_data;
	erase();

	if (flagUsername)
	{
		move(iter += 2, 5);
		str_data = getModuleStringData(usernameMod.getData());
		printw("%s", str_data.c_str());
		str_data = getModuleStringData(hostNameMod.getData());
		move(iter += 2, 5);
		printw("%s", str_data.c_str());
	}
	if (flagOS)
	{
		move(iter += 2, 5);
		str_data = getModuleStringData(OSMod.getData());
		printw("%s", str_data.c_str());
	}
	if (flagTime)
	{
		move(iter += 2, 5);
		str_data = getModuleStringData(timeMod.getData());
		printw("%s", str_data.c_str());
	}
	if (flagRAM)
	{
		move(iter += 2, 5);
		str_data = getModuleStringData(RAMMod.getData());
		printw("%s", str_data.c_str());
	}
	if (flagCPU)
	{
		move(iter += 2, 5);
		str_data = getModuleStringData(CPUMod.getData());
		printw("%s", str_data.c_str());
		move(iter += 2, 5);
		str_data = getModuleStringData(usageCPUMod.getData());
		printw("%s", str_data.c_str());
	}
	if (flagNetwork)
	{
		move(iter += 2, 5);
		str_data = getModuleStringData(networkMod.getData());
		printw("%s", str_data.c_str());
	}
	if (kotikFlag)
	{
		move(iter += 2, 5);	
		str_data = getModuleStringData(kotikModule.getData());
		printw("%s", str_data.c_str());
		wattron(stdscr, COLOR_PAIR(1) | A_BOLD);
		mvwprintw(stdscr, iter += 2,
			5, "%s", kotikModule.getCatPart().c_str());
		mvwprintw(stdscr, iter += 1,
			5, "%s", kotikModule.getCatPart().c_str());
		mvwprintw(stdscr, iter += 1,
			5, "%s", kotikModule.getCatPart().c_str());
		mvwprintw(stdscr, iter += 1,
			5, "%s", kotikModule.getCatPart().c_str());
		mvwprintw(stdscr, iter += 1,
			5, "%s", kotikModule.getCatPart().c_str());
		mvwprintw(stdscr, iter += 1,
			5, "%s", kotikModule.getCatPart().c_str());
		mvwprintw(stdscr, iter += 1,
			5, "%s", kotikModule.getCatPart().c_str());
		wattroff(stdscr, COLOR_PAIR(1) | A_BOLD);
	}

	box(stdscr, 0, 0);

	refresh();
}





