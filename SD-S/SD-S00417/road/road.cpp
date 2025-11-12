#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair(x,y)
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=1e4+10;
const int M=1e6+10;
const int P=1e3+10;
int n,m,k;
struct edge1{
	int u,v,w;
}dxj[M];
bool cmp(edge1 xx,edge1 yy)
{
	return xx.w<yy.w;
}
int fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge2{
	int to,nxt,w;
}e[M*2];
int head[M*2],tot;
void adde(int x,int y,int w)
{
	e[tot]={y,head[x],w};
	head[x]=tot++;
}
ll c[15],a[15][N];
bool vis[P][P];
map<pair<int,int>,int> mp; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>dxj[i].u>>dxj[i].v>>dxj[i].w;
		}
		sort(dxj+1,dxj+1+m,cmp); ll ans=0;
		for(int i=1;i<=m;i++)
		{
			int fu=find(dxj[i].u),fv=find(dxj[i].v);
			if(fu==fv) continue;
			fa[fu]=fa[fv];
			ans+=dxj[i].w;
		} 
		cout<<ans<<"\n";
		return 0;
	}
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++)
	{
		cin>>dxj[i].u>>dxj[i].v>>dxj[i].w;
	}
	sort(dxj+1,dxj+1+m,cmp); ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int fu=find(dxj[i].u),fv=find(dxj[i].v);
		if(fu==fv) continue;
		fa[fu]=fa[fv];
		ans+=dxj[i].w;
		adde(dxj[i].u,dxj[i].v,dxj[i].w);
		adde(dxj[i].v,dxj[i].u,dxj[i].w);
		mp[{dxj[i].u,dxj[i].v}]=mp[{dxj[i].v,dxj[i].u}]=1;
	} 	
	bool ff=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i]; if(c[i]) ff=1;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(!ff)
	{
		// 特殊性质A 
		// 直接看每条边可不可以被城市化乡村改成两条边？
		// 但城市化乡村之间也可以连边
		// 整个优先队列每次判断一下可不可以换？ 
		// 甚至不用单调？ 
		// 直接看每条边 删了更优就删，加 不优就算了
//		for(int i=0;i<tot;i+=2)
//		{
//			int v=e[i].to,u=e[i+1].to; 
//			if(v<=k) ans=ans-max(0,e[i].w-a[v][u]),e[i].w=min(e[i].w,a[v][u]);
//			if(u<=k) ans=ans-max(0,e[i].w-a[u][v]),e[i].w=min(e[i].w,a[u][v]);			
//		}
		for(int i=0;i<tot;i+=2)
		{
			int v=e[i].to,u=e[i+1].to; 
			int id=-1; ll val=e[i].w; int fff=0;
			for(int j=1;j<=k;j++)
			{
				if(j==v||j==u) 
				{
					for(int m=1;m<=n;m++) if(j!=m&&!mp[{j,m}]&&a[j][m]<val) fff=j,id=m,val=a[j][m];
					//没看连通性 
				}
				else
				if(a[j][u]+a[j][v]<val)
				{
					id=j,val=a[j][u]+a[j][v]; fff=0;
				}	
			}
			ans=ans-e[i].w+val;
			if(id!=-1)
			{
				mp[{u,v}]=mp[{v,u}]=0;
				if(fff)
				{
					adde(fff,id,val); adde(id,fff,val);
					mp[{id,fff}]=mp[{fff,id}]=1;
//					continue;
				}
				else
				{
					adde(id,u,a[id][u]);
					adde(u,id,a[id][u]);
					adde(id,v,a[id][v]);
					adde(v,id,a[id][v]);
					mp[{id,u}]=mp[{u,id}]=1;
					mp[{id,v}]=mp[{v,id}]=1;
				}
			}
		} 
		cout<<ans<<"\n";
		return 0;
	}
	//我菜死了/(ㄒoㄒ)/~~
	//过不了紫砂了 
	return 0;
}

