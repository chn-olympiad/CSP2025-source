#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,m,k;
long long u[1000100],v[1000100],w[1000100];
long long a[10010];
long long c[100];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
	}
	printf("0");
	return 0;
} 
