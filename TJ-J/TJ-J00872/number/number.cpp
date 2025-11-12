#include <bits/stdc++.h>
using namespace std;

long long cnt[15];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9') cnt[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= cnt[i]; j++) printf("%d", i);
	}
	cout << endl;
	return 0;
}
