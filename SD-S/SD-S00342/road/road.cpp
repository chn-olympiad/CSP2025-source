#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+4;
const int M=1e3+5;
ll n,m,k,p[N],f[M][M];
ll sum;
void init()
{
	for(int i=1;i<=n;i++)
		p[i]=i;
}
ll find(int a)
{
	if(a==p[a]) return a;
	return p[a]=find(p[a]);
}
void merge(ll a,ll b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
		p[b]=a;
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		f[u][v]=w;
		f[v][u]=w;
		sum=sum+w;
	}
	cout<<sum;
	return 0;
}

