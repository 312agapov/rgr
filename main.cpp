#include "zapis.h"
#include <string>
#include <fstream>
#include <vector>
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
		cout << "������� 1 ����� ������ ������ \n";
		cout << "������� 2 ����� ���������� ��������� ������ \n";
		cout << "������� 3 ����� ���������� ��� ������\n";
		cout << "������� 4 ����� ����������� �����\n";
		cout << "������� 5 ����� �������� �������\n";
		cout << "������� 6 ����� �������� ����\n";
		cout << "������� 7 ����� ������� �������\n";
		cout << "������� 8 ����� �����\n";
		cin >> a;

		if (a == 1) {
			cout << "������� ��� : ";
			cin >> name;
			phone.SetName(name);

			fstream fout;
            fout.open("phonebook.txt", ios::app);
            fout << phone.name;
            fout << "\n";
            fout.close();

			cout << "������� ������� : ";
			cin >> sname;
			phone.SetSname(sname);

			fout.open("phonebook.txt", ios::app);
            fout << phone.sname;
            fout << "\n";
            fout.close();

			cout << "������� ����� : ";
			cin >> number;
			phone.SetNumber(number);

			fout.open("phonebook.txt", ios::app);
            fout << phone.number;
            fout << "\n------------------------------\n";
            fout.close();
		}

		if (a == 2)
            {
            cout << "�������" << endl;
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
            cout << "������ ���, ������� ��� ����� ��� ������" << endl;
            cin >> poisk;
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
            cout << "������ ���, ������� ��� ����� ��� ������" << endl;
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
                           cunt=1;
                       }
                    }
                    if(cunt==1)
                        {
                       for(int i=0;i<mass.size();i++)
                        {
                            cout << mass[i] << endl;
                        }
                        cout << "�������� ������ �������? 1-��� 2-��\n";
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
                          cout << "������� ���������� ���" << endl;
                          cin >> ss;
                          buffer << ss << endl;
                          cout << "������� ���������� �������" << endl;
                          cin >> ss;
                          buffer << ss << endl;
                          cout << "������� ���������� �����" << endl;
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
            cout << "������ ���, ������� ��� ����� ��� ������" << endl;
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
                        cout << "������� ������ �������? 1-��� 2-��\n";
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
