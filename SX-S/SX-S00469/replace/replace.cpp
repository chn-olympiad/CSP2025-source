#include <bits/stdc++.h>
using namespace std;
const long long P=1e5+7,R=65536;
long long T,n,m,k,ans,sum,num,cnt,flag;
long long vis[100050],fa[100050];
vector<long long>vec[100050];

struct edge
{
	long long u,v,w;
}e[100050];
bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}
long long find(long long x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;++i)
	{
		long long xx=find(e[i].u),yy=find(e[i].v);
		if(xx!=yy)
		{
			fa[xx]=yy;
			sum+=e[i].w;
		}
	}
	for(int i=1;i<=m;++i) cout<<fa[i]<<" ";
	cout<<sum;
	return 0;
}
