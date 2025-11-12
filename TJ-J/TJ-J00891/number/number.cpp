#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000005];
int ai = 1;

bool Cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.length(); i++)
	{
		if('0' <= s[i] && s[i] <= '9')a[ai++] = int(s[i] - '0');
	}
	sort(a + 1, a + ai, Cmp);
	for(int i = 1; i < ai; i++)cout << a[i];
	return 0;
}
