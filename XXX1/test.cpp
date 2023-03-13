#include <iostream>
#include <windows.h>
#include <map>
#include <fstream>
#include <string>
using namespace std;

class User
{
public:
	auto UserData(string password, string login, map<string, string>(usermap)) {
		CheckData(login, password, map<string, string>(usermap));
	}
private:
	void CheckData(string login, string password, map<string, string>(usermap)) {
		string s; ifstream file("userdata.txt");bool key = false;
		while (getline(file, s)){
			if (s == login + password) key = true;
		}
		if (key == true) { cout << "\n�� ������� ������������!" << endl; }
		else { cout << "\n�������� ����� ��� ������!" << endl; }
	}
};

int main() {
	bool start = true;
	int a;
	string login, password, newlogin, newpassword;
	map <string, string> usermap;
	setlocale(LC_ALL, "Rus");
	User user1;

	cout << "������� ������� �����!";
	while (start) {
		cout << "\n�������� ���� �� �������� ������������ ����!\n\n-���������������� � ������� - 0.\n-������� ����� ������� - 1.\n-��������� ��������� - 2" << endl;
		cin >> a;
		if (a == 0) {
			cout << "������� �����:" << endl; cin >> login;
			cout << "������� ������:" << endl; cin >> password;
			user1.UserData(password, login, map<string, string>(usermap));
		}
		else if (a == 1) {
			ofstream fileuser("userdata.txt", ios::out | ios::app);
			cout << "������� �����:" << endl; cin >> newlogin;
			cout << "������� ������:" << endl; cin >> newpassword;
			string s; ifstream file("userdata.txt"); bool createuser = true;
			while (getline(file, s)) {
				if ((s == newlogin + newpassword) or (s == newlogin)) createuser = false;
			}
			if (createuser == true) {
				cout << "����������� ���������, ������ �� ������ ����������������." << endl;
				usermap.insert(make_pair(newlogin, newpassword));
				fileuser << newlogin + newpassword << endl; fileuser << newlogin << endl;
			}
			else { cout << "������� � ����� ������� ��� ����������" << endl; }
		}
		else if (a == 2) { start = 0; }
	}
	cout << "��������� ���������!" << endl;
	return 0;
}