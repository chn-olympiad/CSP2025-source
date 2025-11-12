#include<bits/stdc++.h>
#define ll long long
#define m(a) memset(a,0,sizeof(a))
using namespace std;
const int NN=1e4+5,MM=15,RR=2e7+5;
int n,m,k,t;
struct node{
	int u,v,w;
}r[RR],p[MM][NN];
int c[MM];
int book[NN],g[MM],l,s[NN];
ll ans;
//vector< pair<int,int> > a[NN];
bool mycmp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		//x.push_back({y,z});
		//y.push_back({x,z});
		r[i].u=x;
		r[i].v=y;
		r[i].w=z;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&p[i][j].w);
			p[i][j].u=i;
			p[i][j].v=j;
		}
	}
	sort(r+1,r+m+1,mycmp);
	for(int i=1;i<=m;i++)
	{
		if(book[r[i].u]==1&&book[r[i].v]==1) continue;
		ans+=r[i].w;
		g[++l]=i;
		if(book[r[i].u]==0){book[r[i].u]=1;t++;}
		if(book[r[i].v]==0){book[r[i].v]=1;t++;}
		if(t==n) break;
	}
    printf("%lld",ans);
	return 0;
}

