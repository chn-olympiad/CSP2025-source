#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6;
ll n,m,k,sum;
	ll u[maxn],v[maxn],cost1[maxn];
	ll cost2[maxn];
	ll use[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;++i)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&cost1[i]);
	}
	for(int i=1;i<=k;++i)
	{
		scanf("%lld",&use[i]);
		for(int j=1;j<=n;++i)
		{
			scanf("%lld",&cost2[j]);
		}
	}
	for(int i=1;i<=m;++i)
	{
		sum+=cost1[i];
	}
	printf("%lld",sum);
	return 0;
} 