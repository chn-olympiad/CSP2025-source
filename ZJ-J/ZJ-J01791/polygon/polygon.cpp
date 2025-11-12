#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
long long n,a[N],ans,maxx,jc[N];
void dfs(long long i,long long sum,long long maxx){
	if(i==n+1){
		if(sum>2*maxx) ans=(ans+1)%mod;
		return ;
	}
	dfs(i+1,sum+a[i],max(maxx,a[i]));
	dfs(i+1,sum,maxx);
}
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
    	if(b&1) ans=ans*a%mod;
    	a=a*a%mod,b>>=1;
	}return ans;
}
long long C(long long n,long long k){return jc[n]*qpow(jc[k],mod-2)%mod*qpow(jc[n-k],mod-2)%mod;}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",a+i),maxx=max(maxx,a[i]);
	if(maxx==1){
		jc[0]=1;
		for(long long i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
		for(long long i=3;i<=n;i++) ans=(ans+C(n,i))%mod;
		printf("%lld",ans);
		return 0;
	}
	dfs(1,0,0);printf("%lld",ans);
	return 0;
}

