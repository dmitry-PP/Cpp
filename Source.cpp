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
    string vowels = "аоыияюэеуё";

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
    string vowels = "аоыияюэеуё";

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

    cout << "Введите слово: ";
    cin >> word;

    cout << "Выберите действие:" << endl;
    cout << "1. Слово выводится задом наперед." << endl;
    cout << "2. Вывести слово без гласных." << endl;
    cout << "3. Вывести слово без согласных." << endl;
    cout << "4. Рандомно раскидывать буквы заданного слова." << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Результат: " << reverse(word) << endl;
        break;
    case 2:
        cout << "Результат: " << removeVowels(word) << endl;
        break;
    case 3:
        cout << "Результат: " << removeConsonants(word) << endl;
        break;
    case 4:
        cout << "Результат: " << shuffle(word) << endl;
        break;
    default:
        cout << "Неверный выбор." << endl;
        break;
    }

    return 0;
}
