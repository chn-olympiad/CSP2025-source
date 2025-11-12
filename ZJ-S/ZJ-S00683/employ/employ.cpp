#include<bits/stdc++.h>
using namespace std;
char s[505];
int a[505];
int k[505];
bool st[505];
int n,m;
int ans=0;
void dfs(int t)
{
	if(t>n)
	{
		int cnt=0,cur=0;
		for(int i=1;i<=n;i++)
		  if(s[i]=='0'||a[k[i]]<=cnt) cnt++;
		  else cur++;
		if(cur>=m) ans++,ans%=998244353;
	}
	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			k[t]=i;
			st[i]=true;
			dfs(t+1);
			st[i]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
