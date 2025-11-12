#include<bits/stdc++.h>
using namespace std;
map<string, string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	while(q--)
	{
		string s, t;
		cin >> s >> t;
		int ds, de;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] != t[i])
			{
				ds = i;
				break;
			}
		}
		for(int i = s.size()-1; i >= 0; i--)
		{
			if(s[i] != t[i])
			{
				de = i;
				break;
			}
		}
		long long ans = 0;
		for(int i = 0; i <= ds; i++)
		{
			for(int j = de; j < s.size(); j++)
			{
				if(mp[s.substr(i,j-i+1)] == t.substr(i,j-i+1)) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
