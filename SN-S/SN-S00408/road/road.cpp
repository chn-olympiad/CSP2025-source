//YangRuibin SN-S00408 TYZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=1e6+5,K=15,inf=1ll<<60;
int n,m,k,tot,cnt,num=0,c[K],a[K][N],ans=inf;
int fa[N*2];
struct node{
	int from,to,dis;
	bool operator<(const node &x)const
	{
		return dis<x.dis;
	}
}edge[M*2],g[M*2],tmp[M*2];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void init_mst()
{
	sort(edge+1,edge+tot+1);
	for(int i=1;i<=n;i++)fa[i]=i;
	int nnn=0,ret=0;
	for(int i=1;i<=tot;i++)
	{
		int x=edge[i].from,y=edge[i].to;
		x=find(x),y=find(y);
		if(x==y)continue;
		fa[x]=y,ret+=edge[i].dis;
		g[++cnt]=edge[i];
		++nnn;
		if(nnn==n-1)break;
	}
	ans=min(ans,ret);
}
int my_mst(int kkk)
{
	sort(tmp+1,tmp+num+1);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	int nnn=0,ret=0;
	for(int i=1;i<=num;i++)
	{
		int x=tmp[i].from,y=tmp[i].to;
		x=find(x),y=find(y);
		if(x==y)continue;
		fa[x]=y,ret+=tmp[i].dis;
		++nnn;
		if(nnn==n-1+kkk)break;
	}
//	cerr<<ret<<endl;
	return ret;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,x,y,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&w);
		edge[++tot]={x,y,w};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",c+i);
		for(int j=1;j<=n;j++)
			scanf("%lld",a[i]+j);
	}
	

	init_mst();//After this the number of edges is n-1
//	cerr<<ans<<endl;
	
	for(int s=1;s<(1<<k);s++)
	{
		int now=0,kkk=0;
		for(int i=1;i<=cnt;i++)tmp[i]=g[i];
		num=cnt;
		for(int i=1;i<=k;i++)
		{
			if((s&(1<<(i-1)))==0)continue;
			now+=c[i];++kkk;
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]>=g[cnt].dis)continue;
				tmp[++num]={i+n,j,a[i][j]};
			}
		}
		now+=my_mst(kkk);
//		cerr<<now<<endl;
//		if(s==31)cerr<<n+kkk-1<<' '<<now<<endl;
		ans=min(ans,now);
	}
	
	printf("%lld",ans);
	return 0;
}
