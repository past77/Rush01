#include "UsageCPUModule.hpp"
#include "main.hpp"

UsageCPUModule::UsageCPUModule() : user(0), sys(0), idle(0), d(new Data()), lastUpdateTime(get_time())
{}
UsageCPUModule::~UsageCPUModule()
{
	if (d)
		delete d;
}

UsageCPUModule & UsageCPUModule::operator=(UsageCPUModule const &rhs){
	if (this != &rhs)
		*this = rhs;
	return (*this);
}
UsageCPUModule::UsageCPUModule(UsageCPUModule const &src){
	*this = src;
}


float UsageCPUModule::getUserData()
{
	std::vector<std::string> res;
	if (!d->data.empty())
	{
		res = vecSplit(d->data);
		this->user = stof(res.at(0));
	}
	return this->user;
}

float UsageCPUModule::getSysData()
{
	std::vector<std::string> res;

	if (!d->data.empty())
	{
		res = vecSplit(d->data);
		this->sys = stof(res.at(2));
	}
	return this->sys;
}


float UsageCPUModule::getIdleData(){
	std::vector<std::string> res;

	if (!d->data.empty())
	{
		res = vecSplit(d->data);
		this->idle = stof(res.at(4));
	}
	return this->idle;
}


std::string	UsageCPUModule::setData(){
	FILE *fp;
	char buf[512];
	std::string str;
	std::string str2;
	const std::string findStr = "CPU usage: ";

	fp = popen("top ", "r");
	if (fp)
	{
		while(fgets(buf, sizeof(buf)-1, fp) != NULL)
		{
			str = std::string(buf);
			if (std::string::npos != str.find(findStr))
			{
				str2 = ltrim(str, findStr);
				return str2;
			}
		}
	}
	if (fp)
		pclose(fp);
	return "";
}

void		UsageCPUModule::gatherUsage(float *arr)
{
	
	if (arr)
	{
		arr[0] = getUserData();
		arr[1] = getSysData();
		arr[2] = getIdleData();
	}
}

bool	UsageCPUModule::isReadyForUpdate()
{
	if ((get_time() - lastUpdateTime) >= 3)
	{
		lastUpdateTime = get_time();
		return (true);
	}
	return (false);
}

Data *		UsageCPUModule::getData(void){
	if (isReadyForUpdate())
	{
		this->d->name = "Usage CPU";
		d->data = setData();
	}
	return d;
}