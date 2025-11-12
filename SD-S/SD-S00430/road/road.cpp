#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
struct node
{
	long long u,v,w;
	bool friend operator <(node a,node b)
	{
		return a.w<b.w;
	}
};
vector<node> e1;
vector<node> e2,e;
int n,m,k;
long long ans;
int c[15],ug[15][N];
int fa[N],siz[N];
long long H;
int fnd(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=fnd(fa[x]);
}
void mg(int x,int y)
{
	int a=fnd(x),b=fnd(y);
	if(siz[a]<siz[b]) fa[a]=b,siz[b]+=siz[a];
	else fa[b]=a,siz[a]+=siz[b];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) 
	{
		node p;
		cin>>p.u>>p.v>>p.w;
		e1.push_back(p);
	}
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	sort(e1.begin(),e1.end());
	for(auto i:e1)
	{
		int tu=i.u;
		int tv=i.v;
		int tw=i.w;
		if(fnd(tu)==fnd(tv)) continue;
		else ans+=tw,mg(tu,tv),e2.push_back(i); 
	} 
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>ug[i][j];
	}
	for(int i=1;i<(1<<k);i++)
	{
		e1.clear();
		for(auto j:e2) e1.push_back(j);
		long long tmp=0;
		for(int j=0;j<k;j++)
		{
			if(i&(1<<j))
			{
				tmp+=c[j+1];
				for(int k=1;k<=n;k++)
				{
					e1.push_back(node{j+1+n,k,ug[j+1][k]});
				}
			}
		}
		for(int j=1;j<=n+k;j++) fa[j]=j,siz[j]=1;
		sort(e1.begin(),e1.end());
		int cnt=0;
		for(auto j:e1)
		{
			int tu=j.u;
			int tv=j.v;
			int tw=j.w;
			if(fnd(tu)==fnd(tv)) continue;
			else tmp+=tw,mg(tu,tv),cnt++; 
		} 
		ans=min(ans,tmp);
//		cerr<<i<<'\n';
	}	
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
