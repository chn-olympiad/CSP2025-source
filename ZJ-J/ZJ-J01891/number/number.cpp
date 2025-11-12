#include<bits/stdc++.h>
using namespace std;
string s;
int number[1000005];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s; int cnt = 0;
	for (int i = 0; i < s.length(); i ++)
	{
		if ('0' <= s[i] and '9' >= s[i])
		{
			number[++cnt] = s[i] - '0';
		}
	}
	sort(number + 1, number + cnt + 1);
	for (int i = cnt; i >= 1; i --)
	{
		cout << number[i];
	}
	return 0;
}
