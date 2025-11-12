#include<bits/stdc++.h>
using namespace std;
struct P
{
	int df,xh;
}a[199];
bool cmp(P b,P c)
{
	return b.df>c.df;
}
void dfs(int pm,int x,int y,int zx,int zy,int fx,int sz)
{
	if(sz==pm)
	{
		cout<<y<<" "<<x;
		exit(0);
	}
	if(fx==1&&x!=zx)
	{
		dfs(pm,x+1,y,zx,zy,fx,sz+1);
	}
	if(fx==1&&x==zx)
	{
		dfs(pm,zx,y+1,zx,zy,0,sz+1);
	}
	if(fx==0&&x!=1)
	{
		dfs(pm,x-1,y,zx,zy,fx,sz+1);
	}
	if(fx==0&&x==1)
	{
		dfs(pm,1,y+1,zx,zy,1,sz+1);
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].df;
		a[i].xh=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int pm=0;
	for(int i=1;i<=n*m;i++)
		if(a[i].xh==1)
			pm=i;
	dfs(pm,1,1,n,m,1,1);
	return 0;
}
