#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
//T2大样例4一直输出5206997190
//还520???我一点都不爱T2大样例4 
//18:00找到hack了 
//但调炸了 
const int N=1e5+5;
const int M=2e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m,k;
ll ans;
bool vis[N],use[N];
ll c[N],a[12][N],p,t[12][M];
//int mina[12],minid[12],nxtmin[12],tit[12][N],nxtminid[12];
int f[N],cnts,cnt;
struct node{
	ll u,v,w;
}e[M],shu[N];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x){return (f[x]==x?x:f[x]=find(f[x]));}
void kruskal()
{
	sort(e+1,e+1+cnt,cmp);
	For(i,1,n+100)f[i]=i;
	int k=0;
	For(i,1,cnt)
	{
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y)
		{
			k++;
			ans+=e[i].w;
			//cout<<e[i].u<<' '<<e[i].v<<endl;
			f[x]=y;
			/*shu[++cnts].u=e[i].u;
			shu[++cnts].v=e[i].v;
			shu[++cnts].w=e[i].w;*/
			/*p+=(((!vis[e[i].u])&&e[i].u>n));
			vis[e[i].u]++;
			if(e[i].u>n)t[e[i].u-n][vis[e[i].u]]=e[i].w;*/
		}
		if(k==n-1)break;
	}
}
void solve()
{
	cin>>n>>m>>k;
	For(i,1,m)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
	}
	/*For(i,1,k)
	{
		cin>>c[i];
		For(j,1,n)
		{
			cin>>a[i][j];
			if(a[i][j]<=mina[i])
			{
				nxtmin[i]=mina[i];
				mina[i]=a[i][j];
				nxtminid[i]=minid[i];
				minid[i]=j;
			}
		}
	}
	For(i,1,k)
	{
		For(j,1,n)
		{
			if(a[i][j]!=mina[i])tit[i][j]=minid[i];
			else tit[i][j]=nxtminid[i];
		}
	}
	/*For(i,1,k)
	{
		For(j,1,n)
		{
			e[++cnt].u=n+i;
			e[cnt].v=j;
			e[cnt].w=a[i][j]+c[i];
		}
	}*/
	kruskal();
	/*For(i,1,cnts)
	{
		ll z=inf,p=0,lst=0;
		For(j,1,k)
		{
			z=min(z,a[j][tit[j][e[i].u]]+a[j][e[i].u]+c[j]);
			if(z!=lst)p=j;
			lst=z;
		}
		use[p]=true;
		if(z<shu[i].w)
		{
			ans+=z;
			ans-=shu[i].w;
		}
	}
	/*For(i,1,k)
	{
		if(vis[i+n]>1)ans-=(vis[i+n]-1)*c[i];
		else if(vis[i+n]==1)
		{
			ans-=c[i];
			ans-=t[i][1];
		}
	}*/
	//For(i,1,k)if(use[i])ans+=c[i];
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--)solve();
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

3 2 1
1 2 4
1 3 1
0 100 3 2
*/
