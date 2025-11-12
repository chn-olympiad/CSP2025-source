#include <bits/stdc++.h>

using namespace std;

map<string,vector<string> > h;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		string s,s1;
		cin >> s >> s1;
		
		h[s].push_back(s1);
	}
	
	while (q--)
	{
		string s,s1;
		cin >> s >> s1;
		
		if (s1.size() != s.size())
		{
			cout << 0 << endl;
			continue;
		}
		
		int l = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != s1[i])
			{
				l = i;
				break;
			}
		}
		
		int r = -1;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] != s1[i])
			{
				r = i;
				break;
			}
		}
		
		long long ans = 0;
		for (int i = l; i >= 0; i--)
		{
			for (int j = r; j < s.size(); j++)
			{
				string s2 = s.substr(i,j - i + 1);
				for (int k = 0; k < h[s2].size(); k++)
				{
					if (h[s2][k] == s1.substr(i,j - i + 1))
					{
						ans++;
					}
				}
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}