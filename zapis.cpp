#include "zapis.h"
#include <string>
zapis::zapis() {
	name = "Леонид";
	sname = "Агапов";
	number = "89063060585";
}
zapis::zapis(string _name, string _sname, string _number) {
	name = _name;
	sname = _sname;
	number = _number;
}
zapis::zapis(const zapis &phone) {
	name = phone.name;
	sname = phone.sname;
	number = phone.number;
}
void zapis::print() const {
	cout << name << " | " << sname << " | " << number << "\n\n";
}
void zapis::SetName(string aname)
{
    name = aname;
}
void zapis::SetSname(string asname)
{
    sname = asname;
}
void zapis::SetNumber(string anumber)
{
	number = anumber;
}
string zapis::GetName()
{
    return name;
}
string zapis::GetSname()
{
    return sname;
}
string zapis::GetNumber()
{
    return number;
}

