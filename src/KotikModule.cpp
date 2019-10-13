#include "KotikModule.hpp"

KotikModule::KotikModule(): d(new Data())
{
	d->data = setData();

	catArray[0] = "   |\\_._/|  ";
	catArray[1] = "   | o o |  ";
	catArray[2] = "   (  T  )  ";
	catArray[3] = "  .^`-^-'^. ";
	catArray[4] = "  `.  ;  .' ";
	catArray[5] = "  | | | | | ";
	catArray[6] = " ((_((|))_))";

	catClip[0] = "   | o o |  ";
	catClip[1] = "   |  o o|  ";
	catClip[2] = "   |o o  |  ";
	catClip[3] = "   | 0 0 |  ";
}
KotikModule::~KotikModule()
{
	if (d)
		delete d;
}
KotikModule & KotikModule::operator=(KotikModule const &rhs){
	if (this != &rhs)
	*this = rhs;
	return (*this);
}
KotikModule::KotikModule(KotikModule const &src){*this = src;}

std::string	KotikModule::setData(){
	return "Zaz loves me :)";
}


std::string KotikModule::getCatPart()
{
	static int	body_counter = 6;
	static int	clip_counter = 0;

	body_counter++;
	if (body_counter == 7)
		body_counter = 0;
	if (body_counter == 1)
	{
		clip_counter++;
		if (clip_counter == 4)
			clip_counter = 0;
		return (catClip[clip_counter]);
	}
	return (catArray[body_counter]);
}


Data *		KotikModule::getData(void) {
	d->name = "Cat";
	return d;
}
