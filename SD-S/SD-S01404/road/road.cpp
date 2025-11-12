#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll sum=0,l=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')l=-1;c=getchar();}
	while(isdigit(c)){sum=(sum<<1)+(sum<<3)+(c^48);c=getchar();}
	return sum*l;
}
ll fa[100100],cnt1,cnt2,sum,ans,q[110];
struct edge
{
	ll u,v,w;
	bool operator<(const edge a)const{
		return w<a.w;
	}
}ed[1001000],nw[100100],s[100100];
ll find(ll x)
{
	if(!fa[x])return x;
	return fa[x]=find(fa[x]);
}
ll Merge(ll x,ll y,ll z)
{
	x=find(x),y=find(y);
	if(x==y)return 0;
	fa[x]=y;
	sum--;
	ans+=z;
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll a=read(),b=read(),c=read(),anss=0;
	for(ll i=1;i<=b;i++)
	{
		ed[i].u=read();
		ed[i].v=read();
		ed[i].w=read();
	}
	sort(ed+1,ed+1+b);
	sum=a;
	for(ll i=1;i<=b;i++)
	{
		if(Merge(ed[i].u,ed[i].v,ed[i].w))nw[++cnt1]=ed[i];
		if(sum==1)break;
	}
	anss=ans;
	for(ll i=1;i<=c;i++)
	{
		q[i]=read();
		for(ll j=1;j<=a;j++)s[++cnt2]=(edge){a+i,j,read()};
	}
	sort(s+1,s+cnt2+1);
	for(ll i=1;i<(1<<c);i++)
	{
		ans=0;sum=a;
		for(ll j=1;j<=a+c;j++)fa[j]=0;
		for(ll j=1;j<=c;j++)if((i>>j-1)&1)ans+=q[j],sum++;
		ll now=1;
		for(ll j=1;j<=cnt2;j++)
		{
			if((i>>s[j].u-a-1)&1)
			{
				while(now<=cnt1&&nw[now].w<=s[j].w)
				{
					Merge(nw[now].u,nw[now].v,nw[now].w);
					if(sum==1)break;
					now++;
				}
				Merge(s[j].u,s[j].v,s[j].w);
				if(sum==1)break;
			}
		}
		while(sum!=1&&now<=cnt1)
		{
			Merge(nw[now].u,nw[now].v,nw[now].w);
			now++;
		}
		anss=min(anss,ans);
	}
	cout<<anss;
	return 0;
}
