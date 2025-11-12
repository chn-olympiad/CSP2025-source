#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int n,m,c[505],num;
bool f = true;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (s[i] != '1') {
			f = false;
			num++;
		}
	}
	sort(c,c+n);
	ll ans = 1;
	if (f || m == 1) {
		for (int i = 1; i <= n; i++)
			ans = (ans * i) % MOD;
	} else if(m == n) {
		ans = 1;
	} else {
		for (int i = 1; i <= n-num; i++) {
			ans = (ans * i) % MOD;
		}
	}
	cout << ans;
	return 0;
}
