#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,m,k,net[N],head[N],to[N],ci[N],p,a,b,used[N],minn=N,c;
void addedge(int a,int b,int c)
{
	to[++p]=b;
	net[p]=head[a];
	head[a]=p;
	ci[p]=c;
}
void dfs(int now,int ans,int num)
{
	if(num==n-1)
	{
		minn=min(minn,ans);
		return ;
	}
	for(int i=head[now];i;i=net[i])
	{
		if(used[to[i]]==1)
		{
			continue;
		}
		used[to[i]]=1;
		dfs(to[i],ans+ci[i],num+1);
		used[to[i]]=0;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int j=1;j<=m;j++)
	{
		cin>>a>>b>>c;
		addedge(a,b,c);
		addedge(b,a,c);
	}
	dfs(1,0,0);
	cout<<minn;
	return 0;
} 
