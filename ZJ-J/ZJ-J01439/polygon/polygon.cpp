#include <bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
const ll N = 1e6+5,MOD = 998244353;
ll n,m,cnt[N],sum[N],sum1[N];
void sub2(){
	int a,b,c,ans = 0;
	cin >> a >> b >> c;
	if (a+b > c && a+c > b && b+c > a) cout << 1;
	else cout << 0;
}
void sub1(){
	bool f = 1;
	for (ll i = 1;i <= n;i++){
		ll a;cin >> a;
		if (a != 1) f = 0;
		cnt[a]++;
		m = max(m,a);
	}
	if (f){
		ll ans = 0;sum[0] = 1;
		for (int i = 1;i <= n;i++) sum[i] = sum[i-1]*i%MOD;
		for (int i = 3;i <= n;i++) (ans += sum[n]%MOD/sum[n-i]/sum[i]) %= MOD;
		cout << ans << '\n';
		return;
	}
	ll n1 = 0,n2 = 0,ans = 0;
	for (ll i = 0;i <= m;i++){
		if (cnt[i] == 0) continue;
		for (ll j = 2;j <= cnt[i];j++){
			sum1[i*j] += cnt[i]/j;
			if (sum1[i*j] != 0) n2 = max(n2,i*j);
		}
		for (ll j = 1;j < i;j++){
			sum1[i+j] += cnt[i]*cnt[j];
			if (sum1[i+j] != 0) n2 = max(n2,i+j);
		}
		for (ll j = 1;j <= n1;j++){
			sum1[i+j] += cnt[i]*sum[j];
			if (sum1[i+j] != 0) n2 = max(n2,i+j);
		}
		for (ll j = 2*i+1;j <= n2;j++) ans += sum1[j]*cnt[i];
		n1 = n2;
		for (ll j = 1;j <= n1;j++){
			sum[j] = sum1[j];
		}
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if (n == 3){
		sub2();
	}else sub1();
	return 0;
}
