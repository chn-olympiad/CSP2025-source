#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int mod = 998244353;
void print_inv(){
	vector<ll> fact(n);
	fact[0] = fact[1] = 1;
	for (int i = 2;i <= n;i++){
		fact[i] = fact[i-1]*i%mod;
	}
	ll ans = 0;
	for (int i = 3;i <= n;i++){
		ans = (ans%mod+((fact[n]%mod)/(fact[max(n-i,i)]%mod)%mod)/fact[min(i,n-i)]%mod)%mod;
	}
	cout << ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	bool ss = 1;
	vector<int> a(n+1),sum(n+1);
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
		if(a[i]!= 1) ss=0;
	}
	if (n==3){
		if (sum[3] > a[3]*2){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	if(ss){
		print_inv();
	}
	return 0;
}
