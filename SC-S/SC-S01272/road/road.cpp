#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,k,ans=1145141919810ll;
struct edge
{
	int u,v,w;
}e[1100006],e1[1100006];
int c[15];
int a[15][10004];
int fa[10014];
int findroot(int x)
{
	if(fa[x]==x)return x;
	fa[x]=findroot(fa[x]);
	return fa[x];
}
void join(int x,int y)
{
	if(findroot(x)==findroot(y))return;
	fa[fa[x]]=fa[y];
}

void init(void)
{
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
} 

int Kruscal(int M,int N)
{
	for(int i=1;i<=M;i++)
	{
		e1[i].u=e[i].u;
		e1[i].v=e[i].v;
		e1[i].w=e[i].w;
	}
	sort(e1+1,e1+M+1,cmp);
	int sum=0,cnt=0,pos=0;
	while(cnt<N-1)
	{
		pos++;
		if(findroot(e1[pos].u)==findroot(e1[pos].v))continue;
		//cout<<e1[pos].u<<" "<<e1[pos].v<<" "<<e1[pos].w<<" "<<(findroot(e1[pos].u)==findroot(e1[pos].v))<<endl;
		sum+=e1[pos].w;
		cnt++;
		join(e1[pos].u,e1[pos].v);
	}
	return sum;
}

void dfs(int x,int y,int z,int t)
{
	if(x>k)
	{
		init();
		ans=min(ans,Kruscal(z,n+y)+t);
		return;
	}
	dfs(x+1,y,z,t);
	for(int i=1;i<=n;i++)
	{
		e[z+i].u=x+n;
		e[z+i].v=i;
		e[z+i].w=a[x][i];
	}
	dfs(x+1,y+1,z+n,t+c[x]);
}

signed main(void)
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}
	dfs(1,0,m,0);
	cout<<ans<<endl;
}
