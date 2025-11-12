#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,a[5005],s[5005],cnt,ans;
bool check() {
	if(cnt<3) return false;
	int maxval=0,sumval=0;
	for(int i=1; i<=cnt; i++) {
		maxval=max(maxval,s[i]);
		sumval+=s[i];
	}
	if(sumval>maxval*2) return true;
	return false;
}
void dfs(int pos) {
	if(pos>n){
		if(check()) ans=(ans+1)%mod;
		return; 
	} 
	s[++cnt]=a[pos];
	dfs(pos+1);
	cnt--;
	dfs(pos+1);
}
bool Cc() {
	for(int i=1; i<=n; i++) if(a[i]!=1) return false;
	return true;
}
long long quick_pow(long long lower,long long power) {
	long long ans=1;
	while(power) {
		lower=lower*lower%mod;
		if(power&1) ans=ans*lower%mod;
		power>>=1;
	}
	return ans;
}
long long fac(int x) {
	long long ans=1;
	for(int i=1; i<=n; i++) ans=ans*i%mod;
	return ans;
}
long long C(int n,int m) {
	return fac(n)*quick_pow(fac(n-m),mod-2)%mod*quick_pow(fac(m),mod-2)%mod;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	} 
	if(n<=20) {
		dfs(1);
		cout<<ans;
	}
	else if(Cc()) {
		long long ans=0;
		for(int i=3;i<=n;i++) ans=ans+C(n,i)%mod;
		cout<<ans; 
	}
	return 0;
}

