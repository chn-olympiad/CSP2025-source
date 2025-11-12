#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,ans;
string s[10005][3],t[10005][3];
map<string,bool>mp;
void dfs(string a,string b,int step)
{
	if(step==2)
		return;
	if(a==b)
	{
		ans++;
		return;
	}
	if(mp[a])
		return;
	mp[a]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a.size();j++)
		{
			bool t=1;
			for(int k=j;k<=j+s[i][1].size()-1;k++)
				if(a[k]!=s[i][1][k-j])
					t=0;
			if(t)
			{
				string ne="";
				for(int k=0;k<j;k++)
					ne+=a[k];
				for(int k=j;k<=j+s[i][1].size()-1;k++)
					ne+=s[i][2][k-j];
				for(int k=j+s[i][1].size();k<a.size();k++)
					ne+=a[k];
				dfs(ne,b,step+1);
			}
		}
	}
}
void solve(string a,string b)
{
	dfs(a,b,0);
	cout<<ans<<'\n';
	mp.clear();
	ans=0;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
		solve(t[i][1],t[i][2]);
	}
}