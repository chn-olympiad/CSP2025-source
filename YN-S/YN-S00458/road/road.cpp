#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 90;
int n,m,k;
long long u[maxn],v[maxn],w[maxn],c[maxn],a[maxn];

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%lld %lld %lld",&u[i],&v[i],&w[i]);
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		for(int j = 1;j <= n;j++){
			scanf("%lld",a[j]);
		}
	}
	sort(w+1,w+m+1);
	long long sum =0;
	for(int i = 1;i < m;i++){
		sum += w[i];
	}
	printf("%lld",sum);
	
	return 0;
}	
