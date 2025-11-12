#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	char c[s.size()];
	for (int i = 0; i < s.size(); i++)
	{
		c[i] = s[i];
	}
	char c1[s.size()];
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			c1[j++] = c[i];
		}
	}
	sort(c1, c1 + j);
	string s1 = "";
	for (int i = j - 1; i > 0; i--)
	{
		s1 += c1[i];
	}
	cout << s1;
	return 0; 
} 
