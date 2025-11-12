#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct edge
{
	long long u,v,w;
}e[3000005],ec[300005];
struct node
{
	long long m,w;
	edge d[10005];
}c[15];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
long long ans=-1,anst,fa[10005],cntc;
long long getf(long long u)
{
	if(u!=fa[u])
	{
		fa[u]=getf(fa[u]);
	}
	return fa[u];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i].w;
		c[i].m=1;
		for(int j=1;j<=n;j++)
		{
			cin>>c[i].d[j].w;
			c[i].d[j].v=j;
			if(c[i].d[c[i].m].w>c[i].d[j].w)
			{
				c[i].m=j;
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	e[m+1]={-1,-1,10000000009};
	
	for(int bi=0;bi<(1<<k);bi++)
	{
//		cout<<bi<<'\n';
		bool b[15]={0};
		for(int i=0;i<k;i++)
		{
			b[i+1]=bi&(1<<i);
		}
		anst=0,cntc=0;
		for(int i=1;i<=k;i++)
		{
			if(b[i])
			{
				anst+=c[i].w;
				anst+=c[i].d[c[i].m].w;
				for(int j=1;j<=n;j++)
					ec[++cntc]={c[i].m,c[i].d[j].v,c[i].d[j].w};
			}
		}
		sort(ec+1,ec+cntc+1,cmp);
//		for(int i=1;i<=cntc;i++)
//		{
//			cout<<ec[i].u<<' '<<ec[i].v<<' '<<ec[i].w<<'\n';
//		}
		ec[cntc+1]={-1,-1,10000000007};
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		long long pe=1,pc=1,cnt=1;
		while(cnt<n)
		{
			if(e[pe].w<ec[pc].w||pc>cntc)
			{
				fa[e[pe].u]=getf(e[pe].u);
				fa[e[pe].v]=getf(e[pe].v);
//				cout<<e[pe].u<<' '<<e[pe].v<<'\n';
//				cout<<fa[e[pe].u]<<' '<<fa[e[pe].v]<<'\n';
				if(fa[e[pe].u]!=fa[e[pe].v])
				{
					cnt++;
					fa[fa[e[pe].u]]=fa[e[pe].v];
					anst+=e[pe].w;
				}
				pe++;
//				cout<<'e'<<pe<<' '<<anst<<'\n';
			}
			else
			{
				fa[ec[pc].u]=getf(ec[pc].u);
				fa[ec[pc].v]=getf(ec[pc].v);
//				cout<<ec[pc].u<<' '<<ec[pc].v<<'\n';
//				cout<<fa[ec[pc].u]<<' '<<fa[ec[pc].v]<<'\n';
				if(fa[ec[pc].u]!=fa[ec[pc].v])
				{
					cnt++;
					fa[fa[ec[pc].u]]=fa[ec[pc].v];
					anst+=ec[pc].w;
				}
				pc++;
//				cout<<'c'<<pc<<' '<<anst<<'\n';
			}
		}
		if(ans==-1)
			ans=anst;
		else
		{
			if(anst<ans)
				ans=anst;
		}	
	}
	cout<<ans;
	return 0;
}
