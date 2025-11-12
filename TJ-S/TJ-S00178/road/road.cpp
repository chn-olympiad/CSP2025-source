#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e4+5;
int n,m,k;
struct edge{
	int u,v,w;
}E[N];
int fa[M];
bool cmp(edge b,edge d)
{
	return b.w<d.w;
}
int Find(int x)
{
	if(fa[x]==x) return x;
	return (fa[x]=Find(fa[x]));
}
bool Union(int x,int y)
{
	int fx=Find(x),fy=Find(y);
	if(fx==fy) return false;
	fa[fx]=fy;
	return true;
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
		E[i].u=u,E[i].v=v,E[i].w=w;
	}
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	long long ans=0;
	int num=0;
	for(int i=1;i<=m;i++)
	{
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(Union(u,v)) ans+=w,num++;
		if(num==n-1) break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
