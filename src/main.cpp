#include "GUI.hpp"
#include "CLI.hpp"
#include <sys/time.h>

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

unsigned long long get_time()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long long secondsSinceEpoch =
    (unsigned long long)(tv.tv_sec) * 1000;
	return (secondsSinceEpoch);
}



int		main(int argc, char **argv)
{
    if (argc == 1)
	{
		GUI gui;
		gui.mainloop();
	}
	else if (argc == 2)
	{
		if (std::string(argv[1]) == std::string("gui"))
		{
			GUI gui;
			gui.mainloop();
		}
		else if (std::string(argv[1]) == std::string("cli"))
		{
			CLI cli;
			cli.mainloop();
		}
		else
			std::cout << "Wrong parameter. Usage: ./ft_gkrellm [cli/gui]";
	}
	else
	{
		std::cout << "Wrong parameter. Usage: ./ft_gkrellm [cli/gui]";
	}
    return 0;
}
