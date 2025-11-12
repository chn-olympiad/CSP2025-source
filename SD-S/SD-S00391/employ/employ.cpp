#include <bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
bool vis[505];
long long ans=0;
string s;
void dfs(int cnt,int suc)
{
	if(cnt==n)
	{
		if(suc>=m)
		{
			ans+=1;
			ans%=998244353;
		}
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				if(s[cnt]=='1' && (cnt-suc)<c[i])
				{
					vis[i]=true;
					dfs(cnt+1,suc+1);
					
					vis[i]=false;
				}
				else
				{
					vis[i]=true;
					dfs(cnt+1,suc);
					vis[i]=false;
				}
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

