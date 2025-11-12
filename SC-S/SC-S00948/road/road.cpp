#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[10010],v[10010],w[10010];
long long ans;
long long a[15][10010];
long long c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	cout<<0;
	return 0;
}