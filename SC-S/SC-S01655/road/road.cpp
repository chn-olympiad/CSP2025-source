#include <bits/stdc++.h>
using namespace std;
#define N 100001
struct Edge{
	int to;
	int next;
	int weight;
}edge[N];
int head[N];
int num=0;

void addedge(int u,int v,int w)
{
	edge[num].to=u;
	edge[num].next=v;
	edge[num].weight=w;
	head[num++]=u;
	return;
}
int u[N],v[N],w[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		addedge(u[i],v[i],w[i]);
		addedge(v[i],u[i],w[i]);
	}
	for(int i=1;i<=k;i++)
	{
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}