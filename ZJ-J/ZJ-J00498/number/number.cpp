#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N];
int c[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int num = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int number = (int)s[i] - 48;
			c[number]++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= c[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}

