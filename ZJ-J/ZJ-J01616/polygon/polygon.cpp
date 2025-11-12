#include<bits/stdc++.h>
using namespace std;
const int N=5e3+100,mod=998244353;
long long a[N],inv[N],mul[N];
long long qpow(long long x,long long y) {
	long long ans=1;
	while(y) {
		if(y%2==1) {
			ans*=x;
			ans%=mod;
			y--;
		}
		x*=x;
		x%=mod;
		ans%=mod;
		y/=2;
	}
	return ans;
}
void init() {
	mul[1]=1;
	for(int i=2; i<=N; i++) {
		mul[i]=mul[i-1]*i%mod;
	}
	inv[N]=qpow(mul[N],mod-2);
	for(int i=N-1; i>=1; i--) {
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	inv[0]=1;
}
long long c(int x,int y) {
	return (mul[y]*inv[x]%mod*inv[y-x]%mod+mod)%mod;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	init();
	int n;
	cin>>n;
	long long maxx=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1) {
		long long ans=0;
		for(int i=3; i<=n; i++) {
			ans+=c(i,n);
		}
		cout<<ans<<endl;
	} else if(n==3) {
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) {
			cout<<1<<endl;
		} else {
			cout<<0<<endl;
		}
	} else {
		long long ans=0;
		for(int i=3; i<=n; i++) {
			ans+=c(i,n);
		}
		cout<<ans<<endl;
	}
	return 0;
}
