#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=2e6+10;
int n,m,k,tot,f[N],c[N],mxci=-1;
struct edge{
	int u,v,w;
}e[M<<1];
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int fd(int x)
{
	if(f[x]==x)return x;
	else return f[x]=fd(f[x]);
}
int mp[N+10][N+10];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++tot]={u,v,w};
		e[++tot]={v,u,w};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		mxci=max(mxci,c[i]);
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			//if(j==i) continue;
			mp[i+n][j]=w;
			mp[j][i+n]=w;
			if(c[i]==0) e[++tot]={i+n,j,w};
			if(c[i]==0) e[++tot]={j,i+n,w};
		}
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++) f[i]=i;
		sort(e+1,e+tot+1,cmp);
		int sum=0,cnt=0;
		for(int i=1;i<=tot;i++)
		{
			int u=e[i].u,v=e[i].v;
			int fx=fd(u),fy=fd(v);
			if(fx!=fy)
			{
				sum+=e[i].w;
				cnt++;
				f[fx]=fy;
				if(cnt==n-1)
				{
					cout<<sum<<endl;
					return 0;
				}
			}
		}	
	}
	return 0;
	
}

/*
5 6 3
1 5 1
1 3 100
1 4 100
2 3 7
4 5 10
3 4 100
0 1 2 3 4 5
0 1 2 3 4 5
0 1 2 3 4 5
*/