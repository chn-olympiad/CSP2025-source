//韩心尧 SN-J01145 西安滨河学校 
#include <bits/stdc++.h>
#define int long long

using namespace std;

string s,ans;
int num[10]; 
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		char c = s[i];
		if (c >= '0' && c <= '9')
		{
			num[c - '0']++;
		}
	}
	for (int i = 9;i >= 0;i--)
	{
		ans += string(num[i],'0' + i);
	}
	cout << ans;
	return 0;
}
