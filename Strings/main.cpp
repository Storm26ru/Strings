#include<iostream>
using namespace std;
#define RU setlocale(LC_ALL, "")
#define EN setlocale(LC_ALL, "C")
//#define ASCII
void Print(char str[], const int n);
int string_length(char str[], const int n);
void to_lower(char str[], const int n);
void to_upper(char str[], const int n);
void shrink(char*& str, const int n);
int is_int_number(char str[], const int n);
int to_int_number(char str[], const int n);
int is_palindrome(char str[], const int n);
void shrink1(char str[], const int n);



void main()
{
	
	const int n = 500;
	char* str = new char[n];
	RU; cout << "Введите строку: " << endl;
	cin.getline(str, n);
	cout << "Длина строки: " << string_length(str, n) << endl;
#ifdef ASCII
	for (int i = 0; i < 257; i++) cout << i << "  " << char(i) << endl;
#endif // ASCII
	cout << "Переводим символы в нижний регистр: " << endl;
	to_lower(str, n);
	Print(str, n);
	RU; cout << "Переводим символы в верхний регистр:  " << endl;
	to_upper(str, n);
	Print(str, n);
	RU; cout << "Удаляем лишние пробелы:  " << endl;
	//shrink(str, n);
	shrink1(str, n);
	Print(str, n);
	RU; cout << "Введите строку: " << endl;
	cin.getline(str, n);
	RU; if (is_int_number(str, n)) cout << "Строка является целым числом : " << to_int_number(str, n) << endl;
	else cout << "Строка не является целым число" << endl;
	if (is_palindrome(str, n)) cout << "Строка является палиндромом " << endl;
	else cout << "Строка не является палиндромом " << endl;
	delete[] str;
}
int string_length(char str[], const int n)
{
	for (int i = 0; i < n; i++) if (str[i] == 0) return i+1;
	return 0;
}
void Print(char str[], const int n)
{
	EN;
	for (int i = 0; i < string_length(str, n); i++) cout << str[i];
	cout << endl;
}
void to_lower(char str[], const int n)
{
	for (int i = 0; i < string_length(str, n); i++)
	{
		if(256+str[i] == 240) str[i]=241; // Ё-ё
		if (str[i]>=65 && str[i]<=90 ) str[i] = str[i] + 32;//Латинские
		else if (256+str[i] >= 128 && 256+str[i] <= 143) str[i] = 256+str[i] + 32; //Русские
		else if (256+str[i]>=144 && 256+str[i]<=159 ) str[i] = 256+str[i] + 80; //Русские
	}
}
void to_upper(char str[], const int n)
{
	for (int i = 0; i < string_length(str, n); i++)
	{
		if(256+str[i] == 241) str[i]=240; // Ё-ё
		if (str[i]>=97 && str[i]<=122 ) str[i] = str[i] - 32;//Латинские
		else if (256+str[i] >= 160 && 256+str[i] <= 175) str[i] = 256+str[i] - 32; //Русские
		else if (256+str[i]>=224 && 256+str[i]<=239 ) str[i] = 256+str[i] - 80; //Русские
	}
}
void shrink(char*& str, const int n)
{
	char* bufer = new char[n];
	bufer[0] = str[0];
	for (int i = 1,j=0; i < string_length(str, n); i++)
	{
		if (bufer[j] == str[i] && bufer[j] == 32) continue;
		bufer[++j] = str[i];
	}
		delete[] str;
		str = bufer;
}
int is_int_number(char str[], const int n)
{
	for (int i = 0; i < string_length(str, n) - 1; i++)
	{
		if (!(str[i] >= 48 && str[i] <= 57)) return 0;
	}
	return 1;
}
int to_int_number(char str[], const int n)
{
	int num = 0;
	for (int i = 0,j=0; i < string_length(str, n) - 1; i++)
	{
		switch (str[i])
		{
		case 48: j = 0; break;
		case 49: j = 1; break;
		case 50: j = 2; break;
		case 51: j = 3; break;
		case 52: j = 4; break;
		case 53: j = 5; break;
		case 54: j = 6; break;
		case 55: j = 7; break;
		case 56: j = 8; break;
		case 57: j = 9; break;
		}
		if (j == 0) num *= 10;
		else num = (num + double(j) / 10) * 10;
	} 

	return num;
}
int is_palindrome(char str[], const int n)
{
	for (int i = 0; i < (string_length(str, n)-1)/2; i++)
	{
		if (str[i] != str[(string_length(str, n)-2) - i]) return 0;
	}
	return 1;
}
void shrink1(char str[], const int n)
{
	for (int i = 0; i < string_length(str,n) - 2; i++)
	{
		while (str[i] == str[i + 1] && str[i] == 32)
		{
			for (int j = i + 1; j < string_length(str, n); j++) str[j] = str[j + 1];
		}
	}
}