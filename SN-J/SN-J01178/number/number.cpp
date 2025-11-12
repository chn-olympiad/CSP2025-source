#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], j;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (('0' <= s[i]) && (s[i] <= '9'))
		{
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a, a + j, cmp);
	for (int i = 0; i < j; i++)
	{
		cout << a[i];
	}
	return 0;
}
