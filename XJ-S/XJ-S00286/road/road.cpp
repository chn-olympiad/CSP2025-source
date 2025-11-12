#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,i,j,u[1000005],v[1000005],w[1000005],c[15],a,s[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],w[i]);
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(j=1;j<=n;j++){
			scanf("%lld",&a);
			s[i]+=a;
		}
	}
	sort(s+1,s+n+1);
	cout<<s[1];
	return 0;
}
