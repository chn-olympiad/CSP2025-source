#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,qtt[10];
string s;

signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	n = s.size();
	for (int i = 0;i < n;i++)
	{
		if ('0' <= s[i] && s[i] <= '9') qtt[s[i]-'0']++;
	}
	for (int i = 9;i >= 0;i--)
	{
		for (int j = 1;j <= qtt[i];j++) cout << i;
	}
	return 0;
}
