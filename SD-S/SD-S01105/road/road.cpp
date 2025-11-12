#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e7+10,M=1e4+10;
ll n,m,k,u,v,w,cnt1;
bool cas=1;
struct node
{
	ll u,v,w;
} e[N];
ll fa[M],cnt,ans;
ll a[15][M],c[15];
ll find(ll x)
{
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]); 
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i; 
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	cnt1=m;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0) cas=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
//	cout<<cas<<endl;
	if(cas)
	{
		for(int i=1;i<=k;i++)
		{
			for(int p=1;p<=n;p++)
			{
				for(int q=p+1;q<=n;q++)
				{
					e[++cnt1].u=p;
					e[cnt1].v=q;
					e[cnt1].w=a[i][p]+a[i][q];
				}
			}
		}
//		cout<<cnt1<<endl;
		sort(e+1,e+cnt1+1,cmp);
		for(int i=1;i<=cnt1;i++)
		{
			int aa=find(e[i].u),bb=find(e[i].v);
			if(fa[aa]!=bb)
			{
				fa[aa]=bb;
				ans+=e[i].w;
				cnt++;
			}
			if(cnt==n-1) break;
		}
		cout<<ans;
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int aa=find(e[i].u),bb=find(e[i].v);
		if(fa[aa]!=bb)
		{
			fa[aa]=bb;
			ans+=e[i].w;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	cout<<ans;
	return 0;
	return 0;
}//44pts

