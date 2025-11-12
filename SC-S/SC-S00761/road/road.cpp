#include<bits/stdc++.h>
using namespace std;
int n,m,k,czh[10010][10010],fa[10010];
int h[10010],e[2000010],ne[2000010],w[2000010],idx;
long long ans;
struct nd
{
	int u,v,w;
};
bool pd(nd a,nd b)
{
	return a.w<b.w;
}
int fd(int x)
{
	if(x==fa[x])return x;
	return fa[x]=fd(fa[x]);
}
vector<nd>tr;
void ksk()
{
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		int a=fd(tr[i].u);
		int b=fd(tr[i].v);
		if(fa[a]!=fa[b])
		{
			ans+=tr[i].w;
			fa[b]=a;
			cnt++;
			if(cnt==n-1)break;
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		tr.push_back({u,v,w});
	}
	bool A=true;
	for(int i=1;i<=k;i++)
	{
		cin>>czh[i][0];
		if(czh[i][0]>0)A=false;
		for(int j=1;j<=n;j++)cin>>czh[i][j];
	}
	if(k==0)
	{
		sort(tr.begin(),tr.end(),pd);
		for(int i=1;i<=n;i++)fa[i]=i;
		ksk();
		cout<<ans;
		return 0;
	}
	if(A)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int o=j;o<=n;o++)
				{
					tr.push_back({j,o,czh[i][j]+czh[i][o]});
				}
			}
		}
		sort(tr.begin(),tr.end(),pd);
		ksk();
		cout<<ans;
	}
	return 0;
}