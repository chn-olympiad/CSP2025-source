#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}e[2000004];
int n,m,k;
int fa[10004];
long long ans;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int findx(int x)
{
	if(fa[x]==x)	return x;
	return fa[x]=findx(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++)	scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		int x=e[i].u,y=e[i].v;
		if(findx(x)==findx(y))	continue;
		fa[x]=y;
		ans+=e[i].w;
	}
	printf("%d",ans);
	return 0;
}
