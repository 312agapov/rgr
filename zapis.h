#ifndef LIBR_H
#define LIBR_H

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class zapis {
private:

public:
    string name;
	string sname;
	string number;
	zapis();
	zapis(string _name, string _sname, string _number);
	zapis(const zapis &phone);
	void print() const;
	void SetName(string aname);
	string GetName();
	void SetSname(string asname);
	string GetSname();
	void SetNumber(string anumber);
	string GetNumber();
};

#endif
