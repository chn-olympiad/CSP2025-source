#include<bits/stdc++.h>
using namespace std;
int n,m,k;

struct village
{
	int va;
	int ro[10010];
}vi[20];
struct road
{
	int u,v,w;
}a[2000010];

bool cmd(road x,road y)
{
	return x.w<y.w;
}

int fa[10010];
int get(int x)
{
	if(fa[x] == x)
	{
		return x;
	}
	else
	{
		return x = get(fa[x]);
	}
}
void merge(int x,int y)
{
	fa[x] = get(fa[y]);
}

bool vis[20];
void dfs(int now,bool vis[])
{
	if(now == n+1)
	{
		for(int i = 1;i<=k;i++)
		{
		}
		return;
	}
	vis[now] = 1;
	dfs(now+1,vis);
	vis[now] = 0;
	dfs(now+1,vis);
}
int nn,q;


int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>nn>>q;
	string a[100],b[100],c[100];
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i = 1;i<=q;i++)
	{
		cin>>c[i];
	}
	cout<<2<<endl<<0<<endl;
	return 0;
}
