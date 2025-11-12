#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int u,v,w;
}A[1000011];
int F[10021];
int N,M,K;
long long ans;
int G[10011][11];
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
int find(int u)
{
//	cout<<u<<" ";
	if(F[u]!=u)
	{
		F[u]=find(F[u]);
	}
	return F[u];
}
void merge(int a,int b,int w)
{
	if(a!=b)
	{
		F[a]=b;
		ans+=w;
	}
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++)F[i]=i;
	for(int i=1;i<=M;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		A[i]={u,v,w};
	}
	for(int i=1;i<=K;i++)
	{
		int w;
		cin>>w;
		ans+=w;
		for(int j=1;j<=N;j++)
		{
			cin>>G[j][i];
		}
	}
	sort(A+1,A+M+1,cmp);
	for(int i=1;i<=M;i++)
	{
		int u=A[i].u,v=A[i].v,w=A[i].w;
		int a=find(u),b=find(v);
		if(a==b)continue;
		long long MIN=w;int t=0;
		for(int j=1;j<=K;j++)
		{
			if(G[u][j]+G[v][j]<MIN)
			{
				MIN=G[u][j]+G[v][j];
				t=j;
			}
		}
		if(t)
		{
			t=find(t);
			merge(a,t,G[u][t]);
			merge(b,t,G[v][t]);
		}else
		{
			merge(a,b,w);
		}
	}
	cout<<ans;
	return 0;
}
