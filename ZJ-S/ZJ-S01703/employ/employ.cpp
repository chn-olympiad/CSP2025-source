#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 10;
const int mod = 998244353;
int n, m, a[N], t[N], ans;
string s;
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i ++) cin >> a[i], t[i] = i;
	do {
		int c = 0, sum = 0;
		for(int i = 1; i <= n; i ++) {
			if(c >= a[t[i]]) c ++;
			else if(s[i - 1] == '0') c ++;
			else sum ++;
		} 
		if(sum >= m) ans ++, ans %= mod;
	}while(next_permutation(t + 1, t + 1 + n));
	cout << ans;
	return 0;
}


