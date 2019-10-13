#ifndef MAIN_HPP
# define MAIN_HPP

#include "IMonitorModule.hpp"

std::string rtrim(const std::string& s);

std::string ltrim(const std::string& s,const std::string findStr);

std::vector<std::string> vecSplit(std::string str);

#endif