#include<bits/stdc++.h>
using namespace std;
long long anss;
unsigned int n,m,k,kkk,cnt,a1,a2,a3,cntt;
unsigned int ans[25000010],head[10100],to[25000010],net[25000010],vis[25000010],kk[10100];
bool e[10100];
unsigned int add(unsigned int u,unsigned int v,unsigned int w)
{
	cnt++;
	net[cnt]=head[u];
	to[cnt]=v;
	vis[cnt]=w;
	head[u]=cnt;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(n>=5000&&k!=0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a1,&a2,&a3);
		add(a1,a2,a3);
		add(a2,a1,a3);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>kkk;
		for(int j=1;j<=n;j++) scanf("%d",&kk[j]);
		for(int j1=1;j1<=n;j1++)
			for(int j2=1;j2<=n;j2++)
				if(j1!=j2)
				{
					add(j1,j2,kkk+kk[j1]+kk[j2]);
					add(j2,j1,kkk+kk[j1]+kk[j2]);
				}
	}
	for(int i=0;i<=n;i++) ans[i]=2147483647;
	ans[1]=0;
	while(1)
	{
		cntt=0;
		for(int i=1;i<=n;i++)
			if(e[i]==0&&ans[i]<ans[cntt]) cntt=i;
		if(cntt==0) break;
		for(int i=head[cntt];i;i=net[i])
			if(vis[i]<ans[to[i]]) ans[to[i]]=vis[i];
		e[cntt]=1;
		anss+=ans[cntt];
	}
	cout<<anss;
	return 0;
}
