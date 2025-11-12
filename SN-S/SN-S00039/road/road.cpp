#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e4+5;
const int M=1e6+5;
const int K=15;
int n,m,k,i,j,val,lst=0,res,fa[N],cst[N],now_n,top;
struct edge
{
	int u,v,w;
	friend bool operator <(edge x,edge y)
	{
		return x.w<y.w;
	}
}e[M],rd[K][N],now_rd[N],tmp;
int f(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=f(fa[x]);
}
void kruskal1()
{
	int cnt=0;
	sort(e+1,e+1+m);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int U=f(e[i].u),V=f(e[i].v);
		if(U==V) continue;
		fa[U]=V;
		rd[0][cnt+1]=e[i];
		lst+=e[i].w;
		if(++cnt==n-1) break;
	}
	return;
}
void kruskal2()
{
	int cnt=0;
	now_n++;
	for(i=1;i<=now_n;i++) fa[i]=i;
	sort(now_rd+1,now_rd+1+top);
	for(i=1;i<=top;i++)
	{
		int U=f(now_rd[i].u);
		int V=f(now_rd[i].v);
		if(U==V) continue;
		fa[U]=V;
		res+=now_rd[i].w;
		if(++cnt==now_n-1) break;
	}
	now_n--;
	return;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	kruskal1();
	now_n=n;
	for(j=1;j<=k;j++)
	{
		top=0;
		cin>>val;
		res=val;
		for(i=1;i<=n;i++) cin>>cst[i];
		for(i=1;i<now_n;i++) now_rd[++top]=rd[j-1][i];//rd[j-1]的长度是now_n-1
		for(i=1;i<=n;i++) 
		{
			tmp.u=now_n+1,tmp.v=i,tmp.w=cst[i];
			now_rd[++top]=tmp;
		}
		kruskal2();
		if(res<lst)
		{
			now_n++;
			lst=res;
			for(i=1;i<now_n;i++) rd[j][i]=now_rd[i];//now有now_n-1个边 
		}
		else
		{
			for(i=1;i<now_n;i++) rd[j][i]=rd[j-1][i];
		}
	}
	cout<<lst<<'\n';
	return 0;
}
