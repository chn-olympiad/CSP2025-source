#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[500005],top,tp;
int ans,res,c[15][10005];
struct ed{
	int u;int v;int w;
}e[2000005],stk[2000005];
bool cmp(const ed &x,const ed &y)
{
	return x.w<y.w;
}
int fd(int x)
{
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
bool moo(int x,int y)
{
	x=fd(x);y=fd(y);
	if(x==y)return false;
	f[x]=y;
	return true;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j,l,u,v,w;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i][0];
		for(j=1;j<=n;j++)cin>>c[i][j];
	}
	for(i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+m+1,cmp);
	for(i=1;i<=m;i++)
	{
//		cout<<top<<"\n";
		u=e[i].u;v=e[i].v;w=e[i].w;
		if(moo(u,v))
		{
			ans+=e[i].w;
			top++;
			stk[top].u=u;
			stk[top].v=v;
			stk[top].w=w;
		}
	}
	
//	cout<<ans<<"\n";
	for(i=1;i<(1ll<<k);i++)
	{
//		cout<<i<<"\n";
		for(j=1;j<=top;j++)e[j]=stk[j];
		tp=top;res=0;
		for(j=1;j<=k;j++)
		{
			if(i&(1ll<<(j-1)))
			{
//				cout<<j<<" ";
				res+=c[j][0];
				for(l=1;l<=n;l++)e[++tp]={n+j,l,c[j][l]};
			}
		}
//		cout<<"\n";
		sort(e+1,e+tp+1,cmp);
		for(j=1;j<=n+k;j++)f[j]=j;
		for(j=1;j<=tp;j++)
		{
//			cout<<e[j].u<<" "<<e[j].v<<" "<<e[j].w<<"\n";
			if(moo(e[j].u,e[j].v))res+=e[j].w;
		}
//		cout<<"|"<<res<<"|\n";
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4


*/