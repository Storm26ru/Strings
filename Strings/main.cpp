#include<iostream>
using namespace std;
//#define ASCII
int string_length(char str[], const int n);
void to_lower(char str[], const int n);
void Print(char str[], const int n);


void main()
{
	
	const int n = 500;
	char str[n];
	cin.get(str,n);
	cout << string_length(str, n) << endl;
#ifdef ASCII
	for (int i = 0; i < 257; i++) cout << i << "  " << char(i) << endl;
#endif // ASCII
	to_lower(str, n);
	Print(str, n);
	char* arr = new char[50];
	cin >> arr;
	cout << arr;
	
		

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
		if (int(str[i])>=65 && int(str[i])<=90 ) str[i] = int(str[i]) + 32;
		else if (int(str[i])>=97 && int(str[i])<=122 ) str[i] = int(str[i]) - 32;

		
	}
}