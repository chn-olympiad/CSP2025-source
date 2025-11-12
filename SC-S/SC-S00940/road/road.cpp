#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=2e6+12;
ll n,k,m,ans;
struct node{
	ll u1,v1,w1;
}t[N];
//int h[N],nxt[N],to[N],w[N],idx;
//void add(int u,int int w1)
//{
//	nxt[idx]=h[u];
//	to[idx]=v;
//	w[idx]=w1;
//	h[u]=idx++;
//}

ll fa[N];
ll find(ll u)
{
	if(fa[u]==u) return u;
	else return fa[u]=find(fa[u]);
}

bool cmp(node x,node y)
{
	return x.w1<y.w1;
}

void Kru()
{
	ll okk=n;
	for(ll i=1;i<=m;i++)
	{
		ll p=find(t[i].u1),q=find(t[i].v1);
		if(p!=q)
		{
			fa[p]=fa[q]=min(p,q);
			ans+=t[i].w1;
			okk--;
		}
		if(okk==1) return ;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&t[i].u1,&t[i].v1,&t[i].w1);
	}
	sort(t+1,t+1+m,cmp);
	
	if(k==0) {
		for(ll i=1;i<=n;i++) fa[i]=i;
		Kru();
		printf("%lld",ans);
	}
	
	return 0;
}
/*
4 6 0
1 2 1
1 3 2
1 4 4
2 4 1
2 3 2
3 4 3
*/

/*
5 6 0
1 2 5
3 1 4
4 5 4
3 5 2
4 1 3
5 1 1
*/