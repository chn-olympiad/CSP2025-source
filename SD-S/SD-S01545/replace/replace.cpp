# include<bits/stdc++.h>
using namespace std;
const int MX = 2e5;
string s[MX + 10][2];
int n;
int q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> s[i][0] >> s[i][1]; 
	}
	while(q--)
	{
		string t1,t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size())
		{
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for(int j = 1;j <= n;j++)
		{
			for(int i = 0;i < t1.size() - s[j][0].size();i++)
			{
				if(t1.substr(0,i + 1) != t2.substr(0,i + 1) || t1.substr(i + s[j][0].size(),t1.size() - i - s[j][0].size() + 1) != t2.substr(i + s[j][0].size(),t2.size() - i - s[j][0].size() + 1))
				{
					continue;
				}
				else
				{
					ans+=(t1.substr(i,s[j][0].size()) == t2.substr(i,s[j][0].size()));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
