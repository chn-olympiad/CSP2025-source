#include <bits/stdc++.h>
#define ll long long
#define endl '\n';
using namespace std;
const ll N = 5e5+5;
ll n,k;
ll b[N],f[N];
void sub1(){//1-12
	for (ll i = 1;i <= n;i++){
		ll a;cin >> a;
		b[i] = b[i-1]^a;
	}
	int bg = 1;
	for (ll i = 1;i <= n;i++){
		for (ll j = bg;j <= i;j++){
			if ((b[i]^b[j-1]) == k) f[i] = max(f[i],f[j-1]+1);
			else f[i] = max(f[i],f[j]);
		}
		if (f[i] > f[i-1]) bg = i;
	}
	cout << f[n] << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	sub1();
	return 0;
}
