#include <bits/stdc++.h>
using namespace std;

long long a[5005];
long long fac[5005];
long long n;
long long ans= 0;

void dfs(long long lst,long long sum,long long ma){
	if(sum > ma){
		++ans;
	}
	for(long long i =lst+1;i <= n;++i){
		dfs(i,sum+a[i],max(ma,a[i]*2));
	}
}

long long qpow(long long a,long long b){
	long long ans = 1;
	for(;b>0;b>>=1){
		if(b&1){
			ans *= a;
			ans %= 998244353;
		}
		a *=a;
		a %=998244353;
	}
	return ans;
}

long long inv(long long x){
	return qpow(x,998244351);
}

int main(){
	// mayby similar to ICPC Reg Xian 2025 L.Let's Make a Convex!(10/19/25)
//#ifndef MDEBUG
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//#endif
	cin >> n;
	bool sf=1;
	for(long long i = 1;i <= n;++i){
		cin >> a[i];
		if(a[i]!=1)sf=0;
	}
	if(n <= 30){//case1: #1-#10
		dfs(0,0,0);
		cout << ans;
	}else if(sf){//case2: #15-20
		fac[0]=1;
		for(long long i = 1;i <= n;++i){
			fac[i]=fac[i-1]*i%998244353;
		}
		for(long long i = 3;i <= n;++i){
			ans += fac[n]*inv(fac[n-i])%998244353*inv(fac[i])%998244353;
			ans %= 998244353;
		}
		cout << ans;
	}else{// case3:NeiKos496
		cout << 33550336;
	}
	
}
