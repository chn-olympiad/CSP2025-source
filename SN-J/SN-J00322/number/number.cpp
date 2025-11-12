//我们扫一遍把0到9存起来
#include<bits/stdc++.h>

using namespace std;

int a[15];
string s;

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.length(); i++)
		if('0' <= s[i] && s[i] <= '9')
			a[s[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		for(int j = 1; j <= a[i]; j++)putchar(i + '0');
	return 0;
} 
