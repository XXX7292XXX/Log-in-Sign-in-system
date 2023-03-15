#include <iostream>
#include <windows.h>
#include <map>
#include <fstream>
#include <string>
using namespace std;

class User
{
public:
	auto UserData(string password, string login, map<string, string>(usermap), bool key) {
		CheckData(login, password, map<string, string>(usermap), key); cout << key;
	}
private:
	 void CheckData(string login, string password, map<string, string>(usermap),bool key) {
		string s; ifstream file("userdata.txt");
		while (getline(file, s)){
			if (s == login + password) key = true;
		}
		if (key == true) { cout << "\n!Access is allowed!" << endl;}
		else { cout << "\n!Acess is denied!" << endl; }
	}
};

int main() {
	bool start = true;bool key = false;
	int a;
	string login, password, newlogin, newpassword;
	map <string, string> usermap;
	setlocale(LC_ALL, "Rus");
	User user1;

	cout << "Good Day!!";
	while (start) {
		cout << "\nChoose one of the operations listed below!\n\n-Log in — 0.\n-Sign in — 1.\n-Quit — 2." << endl;
		cin >> a;
		switch(a) {
			case 0:
				{cout << "Login: "; cin >> login;
				cout << "Password: "; cin >> password;
				user1.UserData(password, login, map<string, string>(usermap), key);
				break; }
			case 1:
				{ofstream fileuser("userdata.txt", ios::out | ios::app);
				cout << "New Login: "; cin >> newlogin;
				cout << "New Password: "; cin >> newpassword;
				string s; ifstream file("userdata.txt"); bool createuser = true;
				while (getline(file, s)) {
					if ((s == newlogin + newpassword) or (s == newlogin)) createuser = false;
				}
				if (createuser == true) {
					cout << "Your account has been successfully created! You can log in now." << endl;
					usermap.insert(make_pair(newlogin, newpassword));
					fileuser << newlogin + newpassword << endl; fileuser << newlogin << endl;
				}
				else { cout << "Account with the same name already exists!" << endl; }
				break; }
			default:
				start = 0;
		}
	}
	cout << "Programm finished!" << endl;
	return 0;
}