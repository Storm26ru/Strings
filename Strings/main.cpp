﻿#include<iostream>
using namespace std;

#define ASCII
void Print(char str[], const int n);
int string_length(char str[], const int n);
void to_lower(char str[], const int n);
void to_upper(char str[], const int n);


void main()
{
	
	const int n = 500;
	char* str = new char[n];
	cin.get(str,n);
	cout << string_length(str, n) << endl;
#ifdef ASCII
	for (int i = 0; i < 257; i++) cout << i << "  " << char(i) << endl;
#endif // ASCII
	to_lower(str, n);
	Print(str, n);
	to_upper(str, n);
	Print(str, n);
		

}
int string_length(char str[], const int n)
{
	for (int i = 0; i < n; i++) if (str[i] == 0) return i;
	return 0;
}
void Print(char str[], const int n)
{
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
