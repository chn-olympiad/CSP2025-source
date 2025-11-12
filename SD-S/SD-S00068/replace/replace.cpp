#include<bits/stdc++.h>
using namespace std;
int n, q;
map<pair<string, string>, int> mp;
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		string st1, st2;
		cin >> st1 >> st2;
		int l = 0, r = st1.length() - 1;
		while(st1[l] == st2[l] && l < st1.length())
			l++;
		while(st1[r] == st2[r] && r >= 0)	
			r--;
		string s = st1.substr(l, r - l + 1);
		string t = st2.substr(l, r - l + 1);
		mp[{s, t}]++;
	}
	for(int i = 1;i <= q;i++)
	{
		string st1, st2;
		cin >> st1 >> st2;
		if(st1.length() != st2.length())
		{
			cout << "0\n";
			continue;
		}
		int l = 0, r = st1.length() - 1;
		while(st1[l] == st2[l] && l < st1.length())
			l++;
		while(st1[r] == st2[r] && r >= 0)
			r--;
		string s = st1.substr(l, r - l + 1);
		string t = st2.substr(l, r - l + 1);
		if(mp.count({s, t}))
			cout << mp[{s, t}] << '\n';
		else
			cout << "0\n";
	}
	return 0;
}

