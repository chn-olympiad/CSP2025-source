#include <bits/stdc++.h>
using namespace std;
const int MAXS = 1e6 + 5;
int num[MAXS], cur = 0;
string s;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if ('0' <= c && c <= '9')
			num[++cur] = c - '0';
	}
	sort(num + 1, num + cur + 1);
	for (int i = cur; i >= 1; i--)
		cout << num[i];
	return 0;
}
