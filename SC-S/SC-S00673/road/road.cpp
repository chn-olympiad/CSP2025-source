#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=5e4+10,INF=1e18;
int n,m,k,ans=INF;
int kc[11],c[11][M];
struct EDGE
{
	int v,w;
};
struct MIN_TREE
{
	int u,v,w;
}e0[M*100],a[M*100];
int cnt,kcnt;
vector<EDGE> e[M];
int st[11];

int fa[M];
int fin(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=fin(fa[x]);
}
bool cmp(MIN_TREE a,MIN_TREE b)
{
	return a.w<b.w;
}

int work_tree()
{
	for(int i=1;i<=n+kcnt;i++)
		fa[i]=i;
//	for(int i=1;i<=cnt;i++)
//		cout<<a[i].u<<" "<<a[i].v<<" "<<a[i].w<<endl;
	sort(a+1,a+cnt+1,cmp);
	int res=0;
	for(int i=1;i<=cnt;i++)
	{
		if(res>ans) return INF;
		int x=a[i].u,y=a[i].v,w=a[i].w;
//		cout<<"P: "<<x<<" "<<y<<" "<<w<<endl;
		x=fin(x),y=fin(y);
		if(x!=y)
		{
//			cout<<"W: "<<a[i].u<<" "<<a[i].v<<endl;
			res+=w;
			fa[y]=fin(x);
		}
	}
	return res;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		e0[i]={x,y,z};
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&kc[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&c[i][j]);
	}
	
	if(k==0)
	{
		cnt=0;
		for(int i=1;i<=m;i++)
			a[++cnt]=e0[i];
		cout<<work_tree();
		return 0;
	}
	
	st[1]=-1;
	while(1)
	{
		int now=1;
		st[now]++;
		while(st[now]>1)
		{
			st[now]=0;
			now++;
			st[now]++;
		}
		if(st[k+1]) break;
		kcnt=cnt=0;
		for(int i=1;i<=m;i++)
			a[++cnt]=e0[i];
		int res=0;
		for(int i=1;i<=k;i++)
			if(st[i])
			{
				res+=kc[i];
				kcnt++;
				for(int j=1;j<=n;j++)
					a[++cnt]={kcnt+n,j,c[i][j]};
			}
//		cout<<"T: ";
//		for(int i=1;i<=k;i++)
//			cout<<st[i]<<" ";
//		cout<<endl;
		ans=min(ans,work_tree()+res);
	}
	
	printf("%lld\n",ans);
	
	return 0;
}