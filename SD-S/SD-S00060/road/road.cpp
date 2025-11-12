#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct edge
{
	int u,v,w;
} ed[M];
int n,m,k,fa[N],ans;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int getf(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=getf(fa[x]);
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			ed[i]={u,v,w};
		}
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(ed+1,ed+m+1,cmp);
		int cnt=1;
		for(int i=1;i<=m&&cnt<n;i++) 
			if(getf(ed[i].v)!=getf(ed[i].u))
				cnt++,fa[getf(ed[i].u)]=getf(ed[i].v),ans+=ed[i].w;
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

