#include <bits/stdc++.h>
using namespace std;
string s;
string ans;
int flag[15];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n;i++)
	{
		if(s[i] <= '9' && s[i] >= '0')
			flag[s[i] - '0'] += 1;
	}
	for(int i = 9; i >= 0;i--)
	{
		if(flag[i] > 0)
		{
			for(int j = 1;j <= flag[i];j++)
				ans += i + '0';
		}
	}
	for(int i = 0;i < ans.length();i++)
		cout << ans[i] - '0';
	return 0;
}
