#include <bits/stdc++.h>
using namespace std;
string s;
int a,b,c,d,e,f,g,h,j,k;
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	cin >> s;
	int n = s.length();
	for (int i = 0;i < n;i++)
	{ 
		if (s[i] == '9')
		{
			a++;
		}
		if (s[i] == '1')
		{
			b++;
		}
		if (s[i] == '2')
		{
			c++;
		}
		if (s[i] == '3')
		{
			d++;
		}
		if (s[i] == '4')
		{
			e++;
		}
		if (s[i] == '5')
		{
			f++;
		}
		if (s[i] == '6')
		{
			g++;
		}
		if (s[i] == '7')
		{
			h++;
		}
		if (s[i] == '8')
		{
			j++;
		}
		if (s[i] == '0')
		{
			k++;
		}
	}
	for (int i = 0;i < a;i++)
	{
		cout << "9";
	}
	for (int i = 0;i < b;i++)
	{
		cout << "1";
	}
	for (int i = 0;i < c;i++)
	{
		cout << "2";
	}
	for (int i = 0;i < d;i++)
	{
		cout << "3";
	}
	for (int i = 0;i < e;i++)
	{
		cout << "4";
	}
	for (int i = 0;i < f;i++)
	{
		cout << "5";
	}
	for (int i = 0;i < g;i++)
	{
		cout << "6";
	}
	for (int i = 0;i < h;i++)
	{
		cout << "7";
	}
	for (int i = 0;i < j;i++)
	{
		cout << "8";
	}
	for (int i = 0;i < k;i++)
	{
		cout << "0";
	}
	
	return 0;
}
