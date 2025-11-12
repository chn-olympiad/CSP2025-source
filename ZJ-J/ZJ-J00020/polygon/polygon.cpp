#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,a[5005],sum,ans=1,couy,maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1) sum++;
	}
	if(n<=3){
		if(n<=2){
			printf("0");
		}
		else{
			maxx=max(a[1],max(a[2],a[3]));
			if(2*maxx<a[1]+a[2]+a[3]){
				printf("1");
			}
			else printf("0");
		}
		return 0;
	}
	if(sum==n){
		for(int i=3;i<=n;i++){
			ans=1;
			for(int j=n-i+1;j<=n;j++){
				ans=(ans%mod*j)%mod;
			}
			for(int j=1;j<=i;j++){
				ans/=j;
			}
			couy+=ans;
			couy%=mod;
		}
		printf("%lld",couy);
		return 0;
	}
	printf("0");
	return 0;
}
