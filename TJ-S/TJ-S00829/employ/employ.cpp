#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 550,  MOD = 998244353;

ll n, m, c[N], ans = 0, fac[N];
string s;
bool flag = true;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> s; s = " " + s;
	for(int i=1; i<=n; i++) cin >> c[i];
	for(int i=0; i<s.length(); i++)
		if(s[i] == '0') {
			flag = false;
			break;
		}

	fac[0] = 1;
	for(int i=1; i<=10; i++) fac[i] = (fac[i-1] * i) % MOD;

	ans = 0;
	for(int i=1; i<=fac[n]; i++) {
		int cnt = 0;
		for(int j=1; j<=n; j++) {
			if(cnt >= c[j]) {
				cnt++; continue;
			}
			if(s[j] == '0') cnt++;
		}
		if(n-cnt >= m) ans = (ans + 1) % MOD;
		next_permutation(c+1, c+1+n);
	}

	cout << ans;

	return 0;
}



