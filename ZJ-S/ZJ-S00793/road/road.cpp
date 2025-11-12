#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k,c[N],a[15][N],fa[N];
vector<int> v1[N],v2[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct node{
	int u,v,w;
}tu[M];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
priority_queue<pair<int,int > >q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	  fa[i]=i;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&tu[i].u,&tu[i].v,&tu[i].w);
		v1[tu[i].u].push_back(tu[i].v);
		v1[tu[i].v].push_back(tu[i].u);
		v2[tu[i].u].push_back(tu[i].w);
		v2[tu[i].v].push_back(tu[i].w);
	}
	sort(tu+1,tu+m+1,cmp);
	for(int i=1;i<=k;++i)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j)
		  scanf("%d",&a[i][j]);
	}
	if(k==0)
	{
		int t=0;
		while(!q.empty())
		{
			
		}
	}
	printf("bye OI");
	return 0;
}
