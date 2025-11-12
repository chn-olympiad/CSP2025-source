#include <bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
using namespace std;

const int N = 510, mod = 998244353;
int n, m, p[N], c[N];
char s[N];
int ans;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> (s + 1);
	for(int i = 1;i <= n;++ i) cin >> c[i], p[i] = i;
	do {
		int q = 0, res = 0;
		for(int i = 1;i <= n;++ i){
			int x = p[i];
			if(s[i] == '0') q++;
			else {
				if(q < c[x]) res++;
				else q++;
			}
		}
		if(res >= m) {
			ans = (ans + 1) % mod;
			//for(int i = 1;i <= n;++ i) cout << p[i] << ' ';
			//cout << '\n';
		}
	} while(next_permutation(p + 1, p + 1 + n));
	cout << ans;
 	return 0;
}