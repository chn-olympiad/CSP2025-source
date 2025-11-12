#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5,M=2e6+5;
struct node{
	ll x,y,w;
	bool friend operator<(node aa,node bb)
	{
		return aa.w<bb.w;
	}
}w[M],w1[M];
ll n,m,k,js,dis[15][N],fa[N],x,y,si[N],cnt,tot,sum;
ll find(ll u)
{
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
		cin>>w[i].x>>w[i].y>>w[i].w;
	stable_sort(w+1,w+1+m);
	for(ll j=1;j<=n;j++)
		fa[j]=j,si[j]=1;
	sum=0;
	for(ll i=1;i<=m;i++)
	{
		x=find(w[i].x);y=find(w[i].y);
		if(x!=y)
		{
			fa[x]=y;
			si[y]+=si[x];
			sum+=w[i].w;
			w1[++cnt].x=w[i].x;w1[cnt].y=w[i].y;w1[cnt].w=w[i].w;
			if(si[y]==n)
				break;
		}
	}
	for(ll i=1;i<=k;i++)
		for(ll j=1;j<=n+1;j++)
			cin>>dis[i][j];
	ll ans=sum;
	for(ll i=1;i<(1<<k);i++)
	{
		tot=cnt;sum=0;js=0;
		for(ll j=1;j<=n+10;j++)
			fa[j]=j,si[j]=1;
		for(ll j=0;j<k;j++)
			if((1<<(j)&i))
			{
				sum+=dis[j+1][1];js++;
				for(ll r=2;r<=n+1;r++)
					w1[++tot].x=n+js,w1[tot].y=r-1,w1[tot].w=dis[j+1][r];
			}
//		cout<<i<<" "<<sum<<'\n';
		stable_sort(w1+cnt+1,w1+tot+1);
		ll l1=1,l2=cnt+1;
		while(l1<=cnt&&l2<=tot)
		{
			if(w1[l1].w<w1[l2].w)
			{
				x=find(w1[l1].x);y=find(w1[l1].y);
				if(x!=y)
				{
					fa[x]=y;
					si[y]+=si[x];
					sum+=w1[l1].w;
					if(si[y]==n+js)
						break;
				}
				l1++;
			}
			else
			{
				x=find(w1[l2].x);y=find(w1[l2].y);
				if(x!=y)
				{
					fa[x]=y;
					si[y]+=si[x];
					sum+=w1[l2].w;
					if(si[y]==n+js)
						break;
				}
				l2++;
			}
		}
		ans=min(ans,sum);
//		cout<<i<<" "<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}