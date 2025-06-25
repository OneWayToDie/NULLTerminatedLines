#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* shrink(char str[]);
bool isPalindrome(const char str[]);
char* RemoveSymbol(char str[], const char symbol);
bool is_int_number(char str[]);
bool to_int_number(char str[]);
bool is_bin_number(char str[]);
bool bin_to_dec(char str[]);
bool is_hex_number(char str[]);
bool hex_to_dec(char str[]);
bool isIPaddress(char str[]);
bool isMACaddress(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	/*char str[] = { 'H', 'e', 'l', 'l', 'o' };
	char str[] = "Hello";*/
	const int SIZE = 256;
	/*char str[SIZE] = "Хорошо     Живет      на      свете      Винни          Пух";*/
	/*char str[] = "Аргентина манит негра";*/
	char str[SIZE] = {};
	cout << "Введите строку: ";
	/*cin >> str;*/
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "Длина строки = " << StringLength(str) << endl;
	/*cout << "Длина строки = " << strlen(str) << endl;*/ // Возвращает размер строки в символах
	cout << "Строка с верхним регистром - " << ToUpper(str) << endl;
	cout << "Строка с нижним регистром - " << ToLower(str) << endl;
	cout << "Удаление лишних пробелов - " << shrink(str) << endl;
	cout << "Строка " << (isPalindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << "Строка " << (is_int_number(str) ? "" : "не ") << "является целым десятичным числом" << endl;
	cout << "Возврат целого десятичного числового значения - " << (to_int_number(str) ? "empty" : str) << endl;
	cout << "Строка " << (is_bin_number(str) ? "" : "не ") << "является целым двоичным числом" << endl;
	cout << "Возврат двоичного числового значения - " << (bin_to_dec(str) ? "empty" : str) << endl;
	cout << "Строка " << (is_hex_number(str) ? "" : "не ") << "является целым шестнадцатеричным числом" << endl;
	cout << "Возврат шестнадцатеричного числового значения - " << (hex_to_dec(str) ? "empty" : str) << endl;
	cout <<  (isIPaddress(str) ? "НЕТ, это не Ip-адрес" : "ДА, это Ip-адрес") << endl;
	cout << (isMACaddress(str) ? "НЕТ, это не MAC-адрес" : "ДА, это MAC-адрес") << endl;
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
bool is_int_number(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] < '0' || str[i] > '9' /*str[i] >= '0' && str[i] <='9'*/)
		{
			return false;
		}
	}
	return true;
}
bool to_int_number(char str[])
{
	int n = is_int_number(str);

	if (n == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool is_bin_number(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] != '0' && str[i] != '1')
		{
			return false;
		}
	}
	return true;
}
bool bin_to_dec(char str[])
{
	int n = is_bin_number(str);

	if (n == false)
	{
		return true;
	}
	return false;
}
bool is_hex_number(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] < '0' || str[i] > '9' && str[i] == 'A' && str[i] == 'B' && str[i] == 'C' && str[i] == 'D' && str[i] == 'E' && str[i] == 'F')
		{
			return false;
		}
	}
	return true;
}
bool hex_to_dec(char str[])
{
	int n = is_hex_number(str);

	if (n == false)
	{
		return true;
	}
	return false;
}
bool isIPaddress(char str[])
{
	//192.168.1.1
	int n = strlen(str);
	if (n == 11)
	{
		for (int i = 0; i < n + 1; i++)
		{
			if (str[3] == '.' && str[7] == '.' && str[9] == '.')
			{
				return false;
			}
		}
	}
	return true;
}
bool isMACaddress(char str[])
{
	//01-23-45-67-89-AB
	//0123.4567.89AB
	int n = strlen(str);
	if (n == 17 || n ==14)
	{
		for (int i = 0; i < n + 1; i++)
		{
			if (((str[2, 5, 8, 11, 14] == '-' || str[2, 5, 8, 11, 14] == ':') && ((str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] <= '0' || str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] >= '9') && (str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] >= 'a' && str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] <= 'b' && str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] <= 'c' && str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] <= 'd' && str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] <= 'e' && str[0, 1, 3, 4, 6, 7, 9, 10, 12, 13, 15, 16] <= 'f')) || ((str[4, 9] == '.') && ((str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] <= '0' || str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] >= '9') && (str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] >= 'a' || str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] <= 'b' || str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] <= 'c' || str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] <= 'd' || str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] <= 'e' || str[0, 1, 2, 3, 5, 6, 7, 8, 10, 11, 12, 13] <= 'f')))))
			{
				return false;
			}
		}
	}
	return true;
}






