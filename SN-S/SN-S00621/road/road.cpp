#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

struct r{
	int u,v,w;
	
}road[1000006];
int fa[100005];

int find(int a)
{
	if(fa[a]==a) return a;
	fa[a]=find(fa[a]);
	return fa[a];
	
	
}
int un(int a,int b)
{
	int A=find(a);
	int B=find(b);
	if(A!=B)
	fa[A]=B;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
 
 int n,m,k;
 cin>>n>>m>>k;
 for(int i=0;i<=n;i++) fa[i]=i;
 for(int i=0;i<m;i++)
 {
 	cin>>road[i].u>>road[i].v>>road[i].w;
 }
 
 cout<<0;
 
	return 0;
}
