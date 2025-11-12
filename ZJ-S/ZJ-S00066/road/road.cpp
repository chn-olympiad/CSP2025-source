#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15,inf=1e9;
int n,m,k,c[K],a[K][N],bst[K],fa[N];
struct Edge
{
	int u,v,w;
	bool operator<(const Edge& oth)const
	{
		return w<oth.w;
	}
}e[M],base[N*K],cur[N*K];
int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||'9'<ch) ch=getchar();
	while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();bst[i]=inf;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
			if(bst[i]==inf||a[i][j]<a[i][bst[i]])
				bst[i]=j;
		}
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	for(int i=1,cnt=0,fu,fv;i<=m;i++)
	{
		fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;ans+=1ll*e[i].w;
		base[++cnt]=e[i];
		if(cnt==n-1) break;
	}
	int kkk=(1<<k);
	long long res;
	for(int cl=0,cnt;cl<kkk;cl++)
	{
		m=res=cnt=0;
		for(int i=1;i<n;i++) cur[++m]=base[i];
		for(int i=1;i<=k;i++)
		{
			if(!((cl>>i-1)&1)) continue;
			res+=1ll*c[i];
			for(int j=1;j<=n;j++)
			{
				if(j==bst[i]) continue;
				cur[++m]=(Edge){bst[i],j,a[i][j]+a[i][bst[i]]};
			}
		}
		if(res>=ans) continue;
		sort(cur+1,cur+m+1);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1,fu,fv;i<=m;i++)
		{
			fu=find(cur[i].u),fv=find(cur[i].v);
			if(fu==fv) continue;
			fa[fu]=fv;res+=1ll*cur[i].w;
			if(res>=ans) break;
			if(++cnt==n-1) break;
		}
		if(res<ans) ans=res;
	}
	cout<<ans;
	return 0;
}
/*
What a... But I just prepared Kruskal...
O(mlogm+2^k*knlogkn),extremely large!!! Thus,I sincerely hope:
That's what"Intel Core Ultra 9 285K CPU @ 3.70 GHz"make differences!
But TLE on"road3.in",WA on"road4.in",maybe gets 0 pts poorly? AFO...
*/
