#include "zapis.h"
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a = 0;
	string name;
	string sname;
    string number;
    string line;
    string poisk;


	zapis phone;
	while(true){
            cout << "Nazhmite 1 chtoby vvesti dannye \n";
            cout << "Nazhmite 2 chtoby posmotret' vvedennye dannye \n";
            cout << "Nazhmite 3 chtoby posmotret' vse dannye\n";
            cout << "Nazhmite 4 chtoby osushchestvit' poisk\n";
            cout << "Nazhmite 5 chtoby izmenit' kontakt\n";
            cout << "Nazhmite 6 chtoby ochistit' fajl\n";
            cout << "Nazhmite 7 chtoby udalit' kontakt\n";
            cout << "Nazhmite 8 chtoby vyjti\n";
            cin >> a;

		if (a == 1) {
			cout << "Vvedite imya : ";
			cin >> name;
			phone.SetName(name);

			fstream fout;
            fout.open("phonebook.txt", ios::app);
            fout << phone.name;
            fout << "\n";
            fout.close();

			cout << "Vvedite familiu : ";
			cin >> sname;
			phone.SetSname(sname);

			fout.open("phonebook.txt", ios::app);
            fout << phone.sname;
            fout << "\n";
            fout.close();

			cout << "Vvedite nomer : ";
			cin >> number;
			phone.SetNumber(number);

			fout.open("phonebook.txt", ios::app);
            fout << phone.number;
            fout << "\n------------------------------\n";
            fout.close();
		}

		if (a == 2)
            {
            cout << "Kontakt" << endl;
			phone.print();
            }

		if (a == 3)
        {
            ifstream in("phonebook.txt");
            while (getline(in, line))
            {
                cout << line << endl;
            }
            in.close();
        }

        if (a == 4)
        {
            ifstream in;
            in.open("phonebook.txt");
            cout << "Vvedite imya, familiu ili nomer dlya poiska" << endl;
            cin >> poisk;
            cout << "********" << endl;
            vector <string> mass;
            int cunt = 0;

            while (in >> line)
            {
                if(line != "------------------------------")
                {
                    mass.push_back(line);
                }
                else
                {
                    for(int i=0;i<mass.size();i++)
                    {
                       if(mass[i]==poisk)
                       {
                           cunt=1;
                       }
                    }
                    if(cunt==1)
                    {
                       for(int i=0;i<mass.size();i++)
                        {
                            cout << mass[i] << endl;
                        }
                        cout << "------------------------------" <<  endl;
                        cunt=0;
                        mass.clear();
                    }
                    else
                        {
                        mass.clear();
                        }
                }
            }
            in.close();
        }

        if (a == 5)
        {
            string line;
            cout << "Vvedite imya, familiu ili nomer dlya poiska" << endl;
            cin >> poisk;
            cout << "********" << endl;
            vector <string> mass;
            int cunt = 0;
            ifstream text("phonebook.txt");
            ofstream buffer("buffer.txt");
            while(text >> line)
            {
                if(line != "------------------------------")
                {
                    mass.push_back(line);
                }
                else
                    {
                    for(int i=0;i<mass.size();i++)
                    {
                       if(mass[i]==poisk)
                       {
                           cunt=1;
                       }
                    }
                    if(cunt==1)
                        {
                       for(int i=0;i<mass.size();i++)
                        {
                            cout << mass[i] << endl;
                        }
                        cout << "Izmenit' dannyi kontakt? 1-net 2-da\n";
                        int f;
                        cin >> f;
                        if(f==1)
                        {
                            for(int i=0;i<mass.size();i++)
                            {
                                buffer << mass[i] << endl;
                            }
                        buffer << "------------------------------" <<  endl;
                        cunt=0;
                        mass.clear();
                        }
                        if(f==2)
                        {
                          string ss;
                          cout << "Vvedite izmenennoe imya" << endl;
                          cin >> ss;
                          buffer << ss << endl;
                          cout << "Vvedite izmenennyu familiu" << endl;
                          cin >> ss;
                          buffer << ss << endl;
                          cout << "Vvedite izmenennyu nomer" << endl;
                          cin >> ss;
                          buffer << ss << endl;
                          buffer << "------------------------------" <<  endl;
                          cunt=0;
                          mass.clear();
                        }
                    }
                    else
                        {
                        for(int i=0;i<mass.size();i++)
                            {
                            buffer << mass[i] << endl;
                            }
                         buffer << "------------------------------\n";
                         mass.clear();
                        }
                }
            }
        text.close();
        buffer.close();
        remove("phonebook.txt");
        rename("buffer.txt", "phonebook.txt");
}

        if (a == 6)
        {
            remove("phonebook.txt");
            ofstream txt("phonebook.txt");
            txt.close();
        }

        if (a == 7)
        {
            string line;
            cout << "Vvedite imya, familiu ili nomer dlya poiska" << endl;
            cin >> poisk;
            vector <string> mass;
            int cunt = 0;
            ifstream text("phonebook.txt");
            ofstream buffer("buffer.txt");
            while(text >> line)
            {
                if(line != "------------------------------")
                {
                    mass.push_back(line);
                }
                else
                    {
                    for(int i=0;i<mass.size();i++)
                    {
                       if(mass[i]==poisk)
                       {
                           cunt++;
                       }
                    }
                    if(cunt!=0)
                    {
                       for(int i=0;i<mass.size();i++)
                        {
                            cout << mass[i] << endl;
                        }
                        cout << "Ydalit' dannyi kantakt? 1-net 2-da\n";
                        int f;
                        cin >> f;
                        if(f==1)
                        {
                            for(int i=0;i<mass.size();i++)
                            {
                                buffer << mass[i] << endl;
                            }
                        buffer << "------------------------------" <<  endl;
                        cunt=0;
                        mass.clear();
                        }
                        if(f==2)
                        {
                          cunt=0;
                          mass.clear();
                        }
                    }
                    else
                        {
                        for(int i=0;i<mass.size();i++)
                            {
                            buffer << mass[i] << endl;
                            }
                         buffer << "------------------------------\n";
                         mass.clear();
                        }
                }
            }
        text.close();
        buffer.close();
        remove("phonebook.txt");
        rename("buffer.txt", "phonebook.txt");
    }

    if (a == 8)
            {
                return 0;
            }
    }
	return 0;
}
