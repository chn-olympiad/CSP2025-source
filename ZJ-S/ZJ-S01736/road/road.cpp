#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,i,j,a[11],head[11000],fa[11000],min_=INT_MAX*2ll*INT_MAX;
bool fl[11];
struct graph
{
	int x,y,len,id;
	friend bool operator<(graph x,graph y)
	{
		if(x.len<y.len)
		  return true;
		return false;
	}
}e[1100001];
int getint()
{
	int sum=0;
	char a=getchar();
	while(a<48||a>57)
	  a=getchar();
	while(a>=48&&a<=57)
	{
		sum=sum*10+a-48;
		a=getchar();
	}
	return sum;
}
int find(int x)
{
	if(fa[x]==x)
	  return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
	return ;
}
void dfs(int x,int s)
{
	if(x>l)
	{
		int i,su=0,sum=0;
		for(i=1;i<=n+l;i++)
		   fa[i]=i;
		for(i=1;i<=m+l*n&&su<n+s-1;i++)
		   if(fl[e[i].id]&&find(e[i].x)!=find(e[i].y))
		   {
		   	sum+=e[i].len;
		   	su++;
		   	merge(e[i].x,e[i].y);
		   }
		for(i=1;i<=l;i++)
		   if(fl[i])
		     sum+=a[i];
		min_=min(min_,sum);
		return ;
	}
	fl[x]=true;
	dfs(x+1,s+1);
	fl[x]=false;
	dfs(x+1,s);
	return ;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=getint();
	m=getint();
	l=getint();
	for(i=1;i<=m;i++)
	{
		e[i].x=getint();
		e[i].y=getint();
		e[i].len=getint();
		e[i].id=0;
	}
	for(i=1;i<=l;i++)
	{
		a[i]=getint();
		for(j=1;j<=n;j++)
		{
			e[m+i*n-n+j].x=j;
			e[m+i*n-n+j].y=n+i;
			e[m+i*n-n+j].len=getint();
			e[m+i*n-n+j].id=i;
		}
	}
	sort(e+1,e+m+l*n+1);
	fl[0]=true;
	dfs(1,0);
	cout<<min_;
	return 0;
}
