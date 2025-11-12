#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q;
map<string ,int>m,vis;
int cnt = 0;

vector<int>v[200006];

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1;i <= n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int len = s1.size();
		int st = 0,ed = 0;
		for(int j = 0 ;j < len;j++)
			if(s1[j]!= s2[j]) 
			{
				st = j;
				break;
			}
		for(int j = len-1;j >= 0;j--)
			if(s1[j] != s2[j]) 
			{
				ed = j;
				break;
			}
		string ss1 = "",ss2 = "";
		for(int j = st;j <= ed;j++)
			ss1 = ss1 + s1[j],ss2 = ss2+s2[j];
		if(vis[ss1] == 0) cnt++,vis[ss1] = cnt;
		if(vis[ss2] == 0) cnt++,vis[ss2] = cnt;
		//cout<<ss1<<" "<<vis[ss1]<<" "<<ss2<<" "<<vis[ss2]<<"\n";
		v[vis[ss1]].push_back(vis[ss2]);
		
	}
	for(int i = 1;i <= q;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size() != s2.size()) 
		{
			cout<<0<<"\n";
			continue;
		}
		int len = s1.size();
		int st = 0,ed = 0;
		for(int j = 0 ;j < len;j++)
			if(s1[j]!= s2[j]) 
			{
				st = j;
				break;
			}
		for(int j = len-1;j >= 0;j--)
			if(s1[j] != s2[j]) 
			{
				ed = j;
				break;
			}
		string ss1 = "",ss2 = "";
		for(int j = st;j <= ed;j++)
			ss1 = ss1 + s1[j],ss2 = ss2+s2[j];
		int ans = 0;
		for(auto j : v[vis[ss1]])
		{
			if(j == vis[ss2]) ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}

