#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N=1e4+5;
const int M=1e6+5;
const int K=15;

struct node
{
	int u,v,l; 
}e[M];
int cnt;

int n,m,k,c[K],a[K][N],fa[N];
ll ans;

bool cmp(node a,node b)
{
	return a.l<b.l;
}

int find(int x)
{
	if(!fa[x]) return x;
	else return fa[x]=find(fa[x]);
}

void krus()
{
	sort(e+1,e+cnt+1,cmp);
	int sum=0;
	for(int i=1;i<=cnt;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v))
		{
			fa[find(u)]=find(v);
			ans+=e[i].l;
			sum++;
		}
		if(sum==n-1) break;
	}
}

bool check()
{
	for(int i=1;i<=k;i++)
	{
		if(c[i]!=0) return 0;
		for(int j=1;j<=n;i++)
			if(a[i][j]!=0) return 0;
	}
	return 1;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		cin>>u>>v>>l;
		if(u>v) swap(u,v);
		e[++cnt]={u,v,l};
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(check()&&k>0)
	{
		cout<<0<<'\n';
		return 0;
	}
	krus();
	cout<<ans<<'\n';
	return 0; 
} 

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
