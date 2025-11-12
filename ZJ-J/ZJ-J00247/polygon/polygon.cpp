#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e3+5,M=2e7+5e6+5,mod=998244353;
int n,a[N];
ll ans,sum[M];
ll ksm(ll a,ll b){
	ll res=1,base=a;
	while(b){
		if(b&1){
			res*=base;
			res%=mod;
		}
		base*=base;
		base%=mod;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=a[i];j++){
			ans+=sum[j];
			ans%=mod;
		}
		for(int j=a[n]+1;j>=0;j--){
			sum[j+a[i]]+=sum[j];
			sum[j+a[i]]%=mod;
		}
		for(int j=1;j<i;j++){
			sum[a[j]+a[i]]++;
			sum[a[j]+a[i]]%=mod;
		}
	}
	ll res=ksm(2,n);
	res=(res-(1+n+n*(n-1)/2)+mod)%mod;
	res=((res-ans)%mod+mod)%mod;
	printf("%lld",res);
	return 0;
}