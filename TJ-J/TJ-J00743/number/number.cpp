#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
const int n = 1000005;
using namespace std;
int a[n];
string str;
int main()
{
	cin >> str;
	for(int i = 1;i <= n;i++)
	{
		if(str.find('9'))
		{
			cout << 9;
		}	
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('8'))
		{
			cout << 8;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('7'))
		{
			cout << 7;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('6'))
		{
			cout << 6;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('5'))
		{
			cout << 5;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('4'))
		{
			cout << 4;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('3'))
		{
			cout << 3;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str.find('2'))
		{
			cout << 2;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str[i] == '1')
		{
			cout << 1;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(str[i] == '0')
		{
			cout << 0;
		}
	}
	return 0;
} 
