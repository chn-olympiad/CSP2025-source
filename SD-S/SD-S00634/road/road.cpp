#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}e[1000005];
int c[1000005];
vector<int> v[10005];
int f[1000005];
int findfa(int x)
{
	if(x==f[x])return x;
	return x=findfa(f[x]);
}
void join(int x,int y)
{
	x=findfa(x);
	y=findfa(y);
	if(y!=x)
	f[y]=f[x];
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
signed main()
{	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(k==0)
	{
		
		int res=0;
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			if(findfa(e[i].u)!=findfa(e[i].v))
			{
				join(e[i].u,e[i].v);
				res+=e[i].w;
				//cout<<res<<endl;
				cnt++;
				if(cnt==n-1)
				{
					cout<<res;
					return 0;
				}
			}
		 } 
	}
	else{
		for(int i=1;i<=m;i++)
		{
			if(e[i].u<=k||e[i].v<=k)
			e[i].w=0;
		}
		sort(e+1,e+m+1,cmp);
		int res=0;
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			if(findfa(e[i].u)!=findfa(e[i].v))
			{
				join(e[i].u,e[i].v);
				res+=e[i].w;
				//cout<<res<<endl;
				cnt++;
				if(cnt==n-1)
				{
					cout<<res;
					return 0;
				}
			}
		} 
	}
	return 0;
}

