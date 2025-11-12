/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4

5 6 0
1 4 6
2 4 5
3 4 4
2 3 7
2 5 7
3 5 4
1 1 1 1 1
*/

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int u,v,w;
}e[1000005];
int a[1000005][15];
int fa[1000005];
int find(int x)
{
	if(fa[x]==x)
		return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	if(x>y)
		swap(x,y);
	if(fa[x]!=fa[y])
		fa[y] = find(fa[x]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int s;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	int i;
	for(i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
			cin>>a[i][j];
	}
	sort(e+1,e+1+m,cmp);
	
	for(i=1;i<=m;i++)
	{
		int fx,fy;
		fx = find(e[i].u);
		fy = find(e[i].v);
		if(fx!=fy)
		{
			merge(fx,fy);
			s += e[i].w;
		}
	}
	cout<<s<<endl;
	return 0;
}
