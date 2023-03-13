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
		if (key == true) { cout << "\nВы успешно авторизованы!" << endl; }
		else { cout << "\nНеверный логин или пароль!" << endl; }
	}
};

int main() {
	bool start = true;
	int a;
	string login, password, newlogin, newpassword;
	map <string, string> usermap;
	setlocale(LC_ALL, "Rus");
	User user1;

	cout << "Доброго времени суток!";
	while (start) {
		cout << "\nВыберете одну из операций переисленных ниже!\n\n-Авторизироваться в аккаунт - 0.\n-Создать новый аккаунт - 1.\n-Завершить программу - 2" << endl;
		cin >> a;
		if (a == 0) {
			cout << "Введите логин:" << endl; cin >> login;
			cout << "Введите пароль:" << endl; cin >> password;
			user1.UserData(password, login, map<string, string>(usermap));
		}
		else if (a == 1) {
			ofstream fileuser("userdata.txt", ios::out | ios::app);
			cout << "Задайте логин:" << endl; cin >> newlogin;
			cout << "Задайте пароль:" << endl; cin >> newpassword;
			string s; ifstream file("userdata.txt"); bool createuser = true;
			while (getline(file, s)) {
				if ((s == newlogin + newpassword) or (s == newlogin)) createuser = false;
			}
			if (createuser == true) {
				cout << "Регистрация завершена, теперь вы можете авторизироваться." << endl;
				usermap.insert(make_pair(newlogin, newpassword));
				fileuser << newlogin + newpassword << endl; fileuser << newlogin << endl;
			}
			else { cout << "Аккаунт с таким логином уже существует" << endl; }
		}
		else if (a == 2) { start = 0; }
	}
	cout << "Программа завершена!" << endl;
	return 0;
}