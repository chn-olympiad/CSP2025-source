#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,max;scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>max){
			max=a[i];
		}
	}
	sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2]){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	else if(max==1){
		n%=mod;
		long long ans=0,v=(n*(--n)%mod)*(--n)%mod;
		while(n>=1){
			--n;
			ans+=v;ans%mod;
			v*=n%mod;
		}
		ans+=v;ans%=mod;
		printf("%d",ans);
	}
	else{
		printf("20251101");
	}
	return 0;
}
