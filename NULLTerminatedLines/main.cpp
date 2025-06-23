#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* shrink(char str[]);
bool isPalindrome(const char str[]);
char* RemoveSymbol(char str[], const char symbol);

void main()
{
	setlocale(LC_ALL, "");
	/*char str[] = { 'H', 'e', 'l', 'l', 'o' };
	char str[] = "Hello";*/
	const int SIZE = 256;
	/*char str[SIZE] = "Хорошо     Живет      на      свете      Винни          Пух";*/
	char str[] = "Аргентина манит негра";
	//cout << "Введите строку: ";
	///*cin >> str;*/
	//SetConsoleCP(1251);
	//cin.getline(str, SIZE);
	//SetConsoleCP(866);
	cout << str << endl;
	cout << "Длина строки = " << StringLength(str) << endl;
	/*cout << "Длина строки = " << strlen(str) << endl;*/ // Возвращает размер строки в символах
	cout << "Строка с верхним регистром - " << ToUpper(str) << endl;
	cout << "Строка с нижним регистром - " << ToLower(str) << endl;
	cout << "Удаление лишних пробелов - " << shrink(str) << endl;
	cout << "Строка " << (isPalindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
}

int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32; // 32 = ' '
		//if (str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;
		//if (str[i] == 'ё') str[i] -= 16;
		str[i] = toupper(str[i]);
	}
	return str;
}
char* ToLower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		//if (str[i] >= 'А' && str[i] <= 'Я')str[i] += 32; 
		//if (str[i] == 'Ё') str[i] += 16;
		str[i] = tolower(str[i]);
	}
	return str;
}
char* shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool isPalindrome(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n+1] {};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	ToUpper(buffer);
	n = strlen(RemoveSymbol(buffer, ' '));
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
char* RemoveSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}



