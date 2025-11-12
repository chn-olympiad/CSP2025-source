#include<bits/stdc++.h>
using namespace std;
long long n,cnt,sum,zuida,ans,a[5005];
bool vis[5005];
void dfs(int x)
{
	if(x>n+1) return;	
	if(x==n+1)
	{
		sum=0,zuida=0;
		for(int i=1;i<=n;i++)
			if(vis[i]) ans++,sum+=a[i],zuida=max(zuida,a[i]);
		if(ans>3&&sum>(zuida*2)) cnt++,cnt%=998244353; 
	}
	vis[x]=1;dfs(x+1);
	vis[x]=0;dfs(x+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt;
	return 0;
}