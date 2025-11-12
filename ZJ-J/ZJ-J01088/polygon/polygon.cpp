#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5010],s[5010],vis[5010];
long long ans,cnt=1,sum;
void dfs(int pos,int m,int level,int st,int mx,int h)
{
	if(st>=pos||level==m)
	{
		if(h>mx&&level==m)sum++;
		return ;
	} 
	dfs(pos,m,level+1,st+1,mx,h+a[st]);
	dfs(pos,m,level,st+1,mx,h);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			cnt++;	
			continue;
		}
		else 
		{
			sum=0;
			for(int j=3;j<=i;j++)dfs(i,j,1,1,a[i],0);
			ans=(ans+sum*cnt%MOD)%MOD;
			cnt=1;
		}
	}
	cout<<ans;
	return 0;
}