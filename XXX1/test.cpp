#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string FILE_NAME = "userdata.txt"; // Имя файла для сохранения данных пользователей
const string ENCRYPTION_KEY = "mysecretkey"; // Ключ для шифрования данных

// Функция для шифрования строки с помощью XOR
string encrypt(const string& data) {
    string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ ENCRYPTION_KEY[i % ENCRYPTION_KEY.size()];
    }
    return result;
}

// Функция для дешифрования строки с помощью XOR
string decrypt(const string& data) {
    return encrypt(data); // Для дешифрования используется та же операция, что и для шифрования
}

// Структура для хранения информации о пользователе
struct User {
    string name;
    string email;
    string password;
};

// Функция для чтения данных о пользователях из файла
void readUsersFromFile(vector<User>& users) {
    ifstream file(FILE_NAME);
    if (file.is_open()) {
        while (true) {
            User user;
            getline(file, user.name);
            getline(file, user.email);
            getline(file, user.password);
            if (file.fail()) break;
            if (!user.name.empty()) {
                user.name = decrypt(user.name);
                user.email = decrypt(user.email);
                user.password = decrypt(user.password);
                users.push_back(user);
            }
        }
        file.close();
    }
}

// Функция для записи данных о пользователях в файл
void writeUsersToFile(const vector<User>& users) {
    ofstream file(FILE_NAME);
    if (file.is_open()) {
        for (const auto& user : users) {
            file << encrypt(user.name) << endl;
            file << encrypt(user.email) << endl;
            file << encrypt(user.password) << endl;
        }
        file.close();
    }
}

// Функция для проверки, есть ли пользователь с указанным email и паролем
bool isUserValid(const vector<User>& users, const string& email, const string& password) {
    for (const auto& user : users) {
        if (user.email == email && user.password == password) {
            return true;
        }
    }
    return false;
}

// Функция для получения индекса пользователя с указанным email и паролем
int getUserIndex(const vector<User>& users, const string& email, const string& password) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].email == email && users[i].password == password) {
            return i;
        }
    }
    return -1;
}

// Функция для вывода информации о пользователе на экран
void printUserInfo(const User& user) {
    cout << "Name: " << user.name << endl;
    cout << "Email: " << user.email << endl;
    cout << "Password: " << user.password << endl;
}

// Функция для изменения информации о пользователе
void changeUserInfo(User& user) {
    cout << "Enter new name (leave empty to skip): ";
    getline(cin, user.name);
    if (!user.name.empty()) {
        cout << "Enter new email: ";
        getline(cin, user.email);
        cout << "Enter new password: ";
        getline(cin, user.password);
        cout << "User info has been updated." << endl;
    }
}

int main() {
    vector<User> users;
    readUsersFromFile(users);
    while (true) {
        cout << "Welcome to our program!" << endl;
        cout << "1. Log in" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(); // Игнорируем символ новой строки, оставшийся в потоке после ввода числа

if (choice == 1) {
            cout << "Enter your email: ";
            string email;
            getline(cin, email);
            cout << "Enter your password: ";
            string password;
            getline(cin, password);
            if (isUserValid(users, email, password)) {
                cout << "You have been logged in successfully!" << endl;
                int index = getUserIndex(users, email, password);
                while (true) {
                    cout << "1. View profile" << endl;
                    cout << "2. Change profile info" << endl;
                    cout << "3. Log out" << endl;
                    cout << "Your choice: ";
                    int choice;
                    cin >> choice;
                    cin.ignore();

                    if (choice == 1) {
                        printUserInfo(users[index]);
                    }
                    else if (choice == 2) {
                        changeUserInfo(users[index]);
                        writeUsersToFile(users);
                    }
                    else if (choice == 3) {
                        cout << "You have been logged out." << endl;
                        break;
                    }
                    else {
                        cout << "Invalid choice." << endl;
                    }
                }
            }
            else {
                cout << "Invalid email or password." << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter your name: ";
            string name;
            getline(cin, name);
            cout << "Enter your email: ";
            string email;
            getline(cin, email);
            cout << "Enter your password: ";
            string password;
            getline(cin, password);
            users.push_back({ name, email, password });
            writeUsersToFile(users);
            cout << "You have been registered successfully!" << endl;
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}