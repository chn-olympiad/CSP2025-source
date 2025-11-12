#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],ans;string s,s23;
bool vis[510];
int p[510];
const int P=998244353;
bool check()
{
	int f=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')f++;
		else if(c[p[i]]<=f)f++;
		//printf("%d %d %d\n",i,p[i],f);
	}
	return n-f>=m;
}
void dfs(int x,int dep)
{
	p[dep]=x;vis[x]=1;
	if(dep==n)
	{
//		for(int i=1;i<=n;i++)cout<<p[i]<<" ";
		if(check())ans=ans%P+1;
		
		vis[x]=0;p[dep]=0;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])dfs(i,dep+1);
	}
	vis[x]=0;p[dep]=0;
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s23;
	s=")"+s23;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		dfs(i,1);
	}
	cout<<ans;
	return 0;
}
