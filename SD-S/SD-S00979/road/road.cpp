#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[11][10005],sum;
bool th,t[10005];
struct c
{
	int vv;
	int ww;
};
vector<c> e[10015];
void dfs(int x,int fa)
{
	if (x==0)
	{
		return;
	}
	int minn=0x3f3f3f,bb=0;
	for (int j=0;j<e[x].size();j++)
	{
		int v=e[x][j].vv,w=e[x][j].ww;
		if (t[v] || v==fa)
			continue;
		if (minn>w)
		{
			minn=w;
			bb=v;
		}
		
	}
	sum+=minn;
	dfs(bb,x);
}
int main()
{
	//Ren5Jie4Di4Ling5%
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,w,v;
	for (int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back((c){v,w});
		e[v].push_back((c){u,w});
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=0;j<=n;j++)
		{
			cin>>a[i][j];
			if (a[i][j]!=0)
			{
				th=true;
			}
		}
	}	
	t[1]=true;
	if (th)
	{
		dfs(1,0);
		cout<<sum;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
