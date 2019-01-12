#include "stdafx.h"
#include "Item.h"

std::ostream & operator<<(std::ostream &os, Item const &i) 
{
	return os << i._name;
}
