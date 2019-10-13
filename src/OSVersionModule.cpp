#include "OSVersionModule.hpp"

OSVersionModule::OSVersionModule(): d(new Data()){}
OSVersionModule::~OSVersionModule(){}

OSVersionModule & OSVersionModule::operator=(OSVersionModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
OSVersionModule::OSVersionModule(OSVersionModule const &src){
	*this = src;
}

std::string	OSVersionModule::setData(){
FILE *fp;
	char buf[256];
	std::string str;
	std::stringstream ss;
	std::string osName;
	std::string s;

	if ((fp = popen("sw_vers", "r")))
	{
		while (fgets(buf, sizeof(buf) - 1, fp) != NULL)
		{
			str = buf;
			std::size_t pos = str.find("\t");
			osName = str.substr (pos + 1  );
			ss << rtrim(osName) << " | ";
		}
		s = ss.str();
	}
	if (fp)
		pclose(fp);
	return s;
}

std::string OSVersionModule::rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of("\n\r\t\f\v");
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}


Data *		OSVersionModule::getData(void){
		d->name = "OS/version";
		d->data = setData();
	return d;
}