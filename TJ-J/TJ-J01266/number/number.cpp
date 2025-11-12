#include<bits/stdc++.h>

using namespace std;

int h[10];
string s, ans;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9') h[s[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--)
	{
		while(h[i])
		{
			ans += char(i + '0');
			h[i]--;
		}
	}
	cout << ans;
	return 0;
}
