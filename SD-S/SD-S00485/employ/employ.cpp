#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[1010],ans,vis[1010];
int modd=998244353;
bool flag=0;
string s;
void dfs(int x,int ok,int cnt,int sory)
{
	vis[x]=1;
	if(cnt>=n)
	{
		if(ok>=m) ans++;
		return;	
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(sory<c[x]&&s[cnt-1]=='1')
			{
				dfs(i,ok+1,cnt+1,sory);
			}
			else dfs(i,ok,cnt+1,sory+1);
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) if(s[i-1]=='0') flag=1;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag==0)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans%modd;
			ans=ans*i;
		}
		cout<<ans%modd<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(s[i-1]=='0') dfs(i,0,1,1);
		else dfs(i,1,1,0);
	}
	cout<<ans%modd<<endl;
	return 0;
} 
