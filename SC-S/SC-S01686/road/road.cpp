#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10,M=6e6+10,K=1e4+15,H=1e3+10;
struct Stu
{
	int u,v;
	long long w;
	bool operator<(const Stu &b) const
	{
		return w>b.w;
	}
}g[M];
int fa[K];
int n,m,k;
int c[30];
int cur;
long long a[K][K];
long long b[H];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(Stu x,Stu y)
{
	return x.w<y.w;
}
long long kruskal()
{
	priority_queue<Stu> q;
	for(int i=1;i<=n*n;i++) q.push(g[i]);
	long long ret=0;
	int fau,fav;
	for(int i=1;i<=n*n;i++)
	{
		fau=find(q.top().u),fav=find(q.top().v);
		if(fau!=fav)
		{
			if(fau==q.top().u&&fau>n)
			{
				for(int j=1;j<=n;j++)
				{
					g[++cur]={fau,j,a[fau][j]};
				}
			}
			fa[fau]=fav;
			ret+=g[i].w;
		}
	}
	return ret;
}
long long kruskal1()
{
//	priority_queue<int,vector<int>,greater<int> > q;
//	for(int i=1;i<=n;i++) q.push()
	sort(g+1,g+m+1,cmp);
	long long ret=0;
	int fau,fav;
	for(int i=1;i<=m;i++)
	{
		fau=find(g[i].u),fav=find(g[i].v);
		if(fau!=fav)
		{
			fa[fau]=fav;
			ret+=g[i].w;
		}
	}
	return ret;
}
signed main()
{
//	cout<<(long long)(32*1000000*log2(1000000))<<endl;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//读入
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+10;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		g[++cur]={u,v,w};
	}
	if(k==0)
	{
		cout<<kruskal1()<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			g[++cur]={n+i,j,a[i][j]+c[i]};
		}
	}
	int ans=kruskal();
	for(int i=n+1;i<=n+k;i++)
	{
		int cnt=0,p=0;
		for(int j=1;j<=n;j++)
		{
			if(fa[j]==i) cnt++,p=j;
		}
		if(fa[i]!=i&&cnt==0)
		{
			ans-=c[i];
			ans-=a[i][fa[i]];
		}
		else if(cnt==1&&fa[i]==i)
		{
			ans-=c[i];
			ans-=a[i][p];
		}
	}
	cout<<ans<<endl;
//	for(int i=1;i<=cur;i++) cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<endl;
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