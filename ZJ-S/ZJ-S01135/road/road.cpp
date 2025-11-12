#include<bits/stdc++.h>
using namespace std;
int f[10005],n,m,k,sum=0;
int a[1005][1005];
struct node
{
	int u,v,w;
}b[1000005];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		f[x]=fy;
}
bool cmp(node o,node p)
{
	return o.w<p.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
		b[i].u=x;
		b[i].v=y;
		b[i].w=z;
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<n;i++)
	{
		merge(b[i].u,b[i].v);
		sum+=b[i].w;
	}
	cout<<sum;
	fclose(stdin);
	flcose(stdout);
	return 0;
}