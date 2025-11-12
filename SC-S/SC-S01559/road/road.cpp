#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e6+50,M=1e4+50;
ll n,m,k;
ll cnt,tot,all,num,ans=1e18,res,sum;
ll a[12][M],fa[M];
bool use[12],flag=1,vis[N];
struct node
{
	ll u,v,w,id;
	friend bool operator < (const node &x,const node &y) {return x.w<y.w;}
} x[N];
inline ll read()
{
	ll k=0;
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	while(c>=48 && c<=57) k=(k<<3ll)+(k<<1ll)+c-48ll,c=getchar();
	return k;
}
inline void get(ll w)
{
	sum=res=0;
	all=n;
	tot=cnt;
	for(ll i=1;i<=k;i++)
	{
		use[i]=w & (1ll<<(i-1));
		if(use[i]) res+=a[i][0],all++;
	}
}
inline ll find(ll x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	num=pow(2,k);
	for(ll i=1;i<=m;i++) 
	{
		x[++cnt].u=read(),x[cnt].v=read(),x[cnt].w=read(),x[i].id=0;
	}
	for(ll i=1;i<=k;i++)
	{
		a[i][0]=read();
		if(a[i][0]) flag=0;
		for(ll j=1;j<=n;j++) 
		{
			a[i][j]=read();
			x[++cnt]=(node){i+n,j,a[i][j],i};
		}
	}
	if(flag)
	{
		get(num-1);
		sort(x+1,x+cnt+1);
		for(ll i=1;i<=n+k;i++) fa[i]=i;
		for(ll i=1;i<=tot;i++)
		{
			if(sum==all-1) break;
			if(!use[x[i].id] && x[i].id!=0) continue;
			ll fu=find(x[i].u),fv=find(x[i].v);
			if(fu==fv) continue;
			sum++;
			res+=x[i].w;
			fa[fu]=fv;
		}
		ans=min(ans,res);
		printf("%lld",ans);
		return 0;
	}
	sort(x+1,x+cnt+1);
	for(ll l=0;l<num;l++)
	{
		get(l);
		for(ll i=1;i<=n+k;i++) fa[i]=i;
		for(ll i=1;i<=tot;i++)
		{
			if(sum==all-1) break;
			if(!use[x[i].id] && x[i].id!=0) continue;
			ll fu=find(x[i].u),fv=find(x[i].v);
			if(fu==fv) continue;
			sum++;
			res+=x[i].w;
			fa[fu]=fv;
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
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