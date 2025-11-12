#include <bits/stdc++.h>
using namespace std;
int b[1000005] = {0}, s = 1;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	for (int i = 0; i <= a.size(); i++)
	{
		if (a[i] == '1')
		{
			b[s] = 1;
			s++;
		}
		else if (a[i] == '2')
		{
			b[s] = 2;
			s++;
		}
		else if (a[i] == '3')
		{
			b[s] = 3;
			s++;
		}
		else if (a[i] == '4')
		{
			b[s] = 4;
			s++;
		}
		else if (a[i] == '5')
		{
			b[s] = 5;
			s++;
		}
		else if (a[i] == '6')
		{
			b[s] = 6;
			s++;
		}
		else if (a[i] == '7')
		{
			b[s] = 7;
			s++;
		}
		else if (a[i] == '8')
		{
			b[s] = 8;
			s++;
		}
		else if (a[i] == '9')
		{
			b[s] = 9;
			s++;
		}
		else if (a[i] == '0')
		{
			b[s] = 0;
			s++;
		}
	}
	sort(b + 1, b + s + 1, cmp);
	for (int i = 1; i <= s - 1; i++)
	{
		cout << b[i];
	}
	return 0;
}
