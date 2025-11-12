#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct node{
	long long u,v,val;
	bool p;
}e[4000005];
long long head[10005];
long long fa[10005];
long long c[10005];
bool mark[10005];
long long ans,cnt;
bool cmp(node c,node d)
{
	return c.val<d.val;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y)
{
	int s1=find(x);
	int s2=find(y);
	if(s1!=s2) fa[x]=y;
}
void kruskal()
{
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;	
		} 
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(cnt==n-1) break;
			if(find(e[i].u)==find(e[i].v)) continue;
			join(e[i].u,e[i].v);
			cnt++;
			ans+=e[i].val;
		}
	}
	else
	{
		for(int i=1;i<=n+k;i++)
		{
			fa[i]=i;	
		} 
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(cnt==n-1) break;
			if(find(e[i].u)==find(e[i].v)) continue;
			join(e[i].u,e[i].v);
			cnt++;
			if(e[i].p==false) 
			{
				ans+=e[i].val;
			}
			else
			{
				ans+=c[e[i].u-n];
				ans+=e[i].val;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].val;
		e[i].p=false;
	}
	if(k==0)
	{
		kruskal();
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=k;i++)
		{
			int x;
			cin>>x;
			for(int j=1;j<=n;j++)
			{
				e[++m].u=n+i;
				e[m].v=i;
				cin>>e[m].val;
				e[i].p=true;
			}
		}
		kruskal();
		cout<<ans<<endl;
	}
}

