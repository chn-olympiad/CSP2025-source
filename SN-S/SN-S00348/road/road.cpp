//juruo xt66666
//T2 是我太菜了看错了还是
//最小生成树模版题？？？黄？
//？？？ 
//不对改造要花钱 
//完了T2又不会惹 
//算了先把特殊性质一打吧
//RP++
//memset(RP,0x3f,sizeof(RP))
//我要上luogu Csp迷惑行为大赏，所以以下关键词
/*
//freopen
//freopen
CCF
1145141919810
orz
%%%
然后就想不起来了 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,k;
struct node
{
	ll x,y,v;
}a[1000000+100000+10];
bool cmp(node x,node y)
{
	return x.v<y.v;
}
ll tot;
ll fee[20][1010];
bool v[10010];
ll c[20];
ll fa[10110];
bool teshuxingzhia=1;
ll find(ll x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void add(ll x,ll y)
{
	x=find(x);y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		ll x,y,v;
		cin>>x>>y>>v;
		a[++tot]={x,y,v};
	}
	if(k==0)
	{
		ll ans=0;
		ll cnt=0;
		sort(a+1,a+tot+1,cmp);
		for(int i=1;;i++)
		{
			ll x=a[i].x,y=a[i].y;
			if(find(x)==find(y))
			{
				continue;
			}
			cnt++;
			add(x,y);
			ans+=a[i].v;
			if(cnt==n-1)
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			teshuxingzhia=0;
		}
	 	for(int j=1;j<=n;j++)
	 	{
	 		cin>>fee[i][j];
		}
	}
	/*if(teshuxingzhia)
	{
		ll ans=0;
		ll cnt=0;
		sort(a+1,a+tot+1,cmp);
		node used[10010];
		for(int i=1;;i++)
		{
			ll x=a[i].x,y=a[i].y;
			if(find(x)==find(y))
			{
				continue;
			}
			cnt++;
			used[cnt]={x,y,a[i].v};
			add(x,y);
			ans+=a[i].v;
			if(cnt==n-1)
			{
				break;
			}
		}
		cout<<ans;
		return 0;
	}*/
	return 0;
}
/*
4 6 0
1 2 1
1 3 2
1 4 3
2 3 4
2 4 6
3 4 5
*/
