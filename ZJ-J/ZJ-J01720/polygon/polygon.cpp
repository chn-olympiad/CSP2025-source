#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans,a[5100],g[5100];
void f(long long i,long long h,long long now,long long m){  //
	if(h>2*a[m] and i>=3){
		ans=(ans+1)%998244353;
	}
	for(long long j=now;j<=n;j++){
		if(!g[j]){
			g[j]=1;
			f(i+1,h+a[j],j,j);
			g[j]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	f(0,0,0,0);
	printf("%lld\n",ans/2);
	return 0;
}
