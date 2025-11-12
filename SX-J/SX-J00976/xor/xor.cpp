#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
const int M = 25, N = 5e5+10;
int s[N][M];
int cnt[M];
bool vis[N];
int n, k, tot, cur, ans, lst, cc, mx, k1;

void MAIN() {
	cin >> n >> k;
	k1 = k;
	while (k) {
		cur++;
		if (k & 1)
			cnt[cur] = 1;
		k >>= 1;
	}
	For(i, 1, n, x) {
		cin >> x;
		mx = max(mx, x);
		if (lst == x) {
			cc++;
			if (cc >= 3 && x != k1) {
				vis[i] = 1;
			}
		} else {
			cc = 1;
			lst = x;
		}
		For(j, 1, 20) s[i][j] = s[i - 1][j];
		tot = 0;
		while (x) {
			tot++;
			if (x & 1)
				s[i][tot]++;
			x >>= 1;
		}
	}
	if (mx < k1) {
		cout << 0 << endl;
		return;
	}
	int j = 1;
	For(i, 1, n) {
		if (vis[i])
			continue;
		bool flag = 0;
		int lstj = j;
		while (j <= i) {
			bool fl = 0;
			For(K, 1, 20) {
				if ((s[i][K] - s[j - 1][K]) % 2 != cnt[K]) {
					fl = 1;
					break;
				}
			}
			if (!fl) {
				flag = 1;
				ans++;
				j = i + 1;
				break;
			}
			++j;
		}
		if (!flag)
			j = lstj;
	}
	cout << ans << endl;
}

signed main() {
	freopen("xor.in", "r", stdin), freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
