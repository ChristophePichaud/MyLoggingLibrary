// CoursC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

class Item;
std::ostream &operator<<(std::ostream &os, Item const &i);

class Exception
{
public:
	Exception(std::string message) : _message(message) {};

public:
	std::string _message;
};

class Item
{
public:
	Item() {}
	~Item() {}
	Item(std::string s) : _name(s) {}

public:
	void ThrowException()
	{
		throw Exception("new exception");
	}

public:
	std::string _name;

};

std::ostream & operator<<(std::ostream &os, Item const &i)
{
	return os << i._name;
}

int main()
{
    std::cout << "Hello World!\n"; 

	Item i1;
	i1._name = "name i1";
	std::cout << i1 << std::endl;

	try
	{
		i1.ThrowException();
	}
	catch (Exception ex)
	{
		std::cout << ex._message << std::endl;
		//throw;
	}

	Item i2;
	i2._name = "name i2";
	i2._name += " for item i2";
	std::cout << i2 << std::endl;

	std::ofstream f("1.txt");
	f << "a string" << std::endl;
	f << i2 << std::endl;
	f.close();

	std::vector<std::string> v1 = { "hello", "world", "!" };
	for (std::string s : v1)
	{
		std::cout << s << std::endl;
	}

	std::vector<std::string>::const_iterator it = v1.begin();
	for (; it != v1.end(); ++it)
	{
		//*it = "modified !";
		std::string s = *it;
		std::cout << s << std::endl;
	}

	std::vector<std::string> v2;
	for (int i = 0; i < 3; i++)
	{
		std::stringstream ss;
		ss << "my string is " << i;
		std::cout << ss.str() << std::endl;
		v2.push_back(ss.str());
	}

	for (std::string s : v2)
	{
		std::cout << s << std::endl;
	}

	std::map<std::string, Item> map1 {
										{"christophep1", {"Lisa"}},
										{"christophep2", {"Audrey"}},
										{"christophep3", {"Edith"}} };
	Item i4;
	i4._name = "????";
	map1.insert_or_assign("christophep4", i4);

	for (std::pair<std::string, Item> kv : map1)
	{
		std::cout << "key: " << kv.first << " value:" << kv.second << std::endl;
	}

	for (auto it2 : map1)
	{
		std::cout << "key: " << it2.first << " value:" << it2.second << std::endl;
	}
}
