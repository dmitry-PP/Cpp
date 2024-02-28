#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;

string reverse(const string& word) {
    string reversestr = "";
    for (int i = word.length(); i>=0; --i)
    {
        reversestr += word[i];
    }
    return reversestr;
}

string removeVowels(const string& word) {
    string result = "";
    string vowels = "���������";

    for (char c : word) {
        char lower_char = tolower(c);
        if (vowels.find(lower_char) == string::npos)
        {
            result += c;
        }
    }
    return result;
}

string removeConsonants(const string& word) {
    string result = "";
    string vowels = "���������";

    for (char c : word) {
        char lower_char = tolower(c);
        if (vowels.find(lower_char) != string::npos) {
            result += c;
        }
    }
    return result;
}

string shuffle(const string& word) {
    string shuffledWord = word;
    shuffle(shuffledWord.begin(), shuffledWord.end(), default_random_engine(time(0)));
    return shuffledWord;
}

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    string word;
    int choice;

    cout << "������� �����: ";
    cin >> word;

    cout << "�������� ��������:" << endl;
    cout << "1. ����� ��������� ����� �������." << endl;
    cout << "2. ������� ����� ��� �������." << endl;
    cout << "3. ������� ����� ��� ���������." << endl;
    cout << "4. �������� ����������� ����� ��������� �����." << endl;
    cout << "��� �����: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "���������: " << reverse(word) << endl;
        break;
    case 2:
        cout << "���������: " << removeVowels(word) << endl;
        break;
    case 3:
        cout << "���������: " << removeConsonants(word) << endl;
        break;
    case 4:
        cout << "���������: " << shuffle(word) << endl;
        break;
    default:
        cout << "�������� �����." << endl;
        break;
    }

    return 0;
}
