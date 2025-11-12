#include<bits/stdc++.h>
using namespace std;
#define int long long
#define iosfst ios::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define lop(i, a, b) for(int i = a; i < b; i ++)
#define dwn(i, a, b) for(int i = a; i >= b; i --)
int a[101000];
//int dp[5010][5010]; //dp[i][j] 表示前i根里面取j根能拼成多少个多边形
const int mod = 998244353;
int ss[101000], vis[101000];
int n;
int C(int x, int y) {
	if(x == y) return 1;
	if(x - y == 1) return x;
	rep(i, 1, x) {
		vis[i] = i;
	}
	if(y > (x - y)) y = x - y;
	rep(i, 2, y) {
		int p = i;
		dwn(j, x, (x - y + 1)) {
			if(__gcd(p, vis[j]) != 1) {
				int k = p;
				p /= __gcd(p, vis[j]);
				vis[j] /= __gcd(k, vis[j]);
			}
			if(p == 1) break;
		}
	}
	int ans = 1;
	dwn(i, x, (x - y + 1)) {
		ans = ans * vis[i] % mod;
	}
	return ans;
}
int ans1 = 0;
void dfs(int sum, int st) {
	if(st > n) return;
	if(sum > 2 * a[st] && st >= 3) {
		ans1 ++;
		ans1 %= mod;
	}
	rep(i, st + 1, n) {
		dfs(sum + a[i], i);
		dfs(sum, i);
	}
	return;
}
signed main() {
	File("polygon");
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(n <= 3) {
		if(n == 1 || n == 2) {
			cout << 0;
			return 0;
		}
		if(a[1] + a[2] <= a[3]) {
			cout << 0;
			return 0;
		} else {
			cout << 1;
			return 0;
		}
	}
	if(a[n] == 1) {
		int ans = 0;
		rep(i, 3, n) {
			ans = (ans + C(n, i)) % mod;
		}
		cout << ans;
		return 0;
	}
	dfs(0, 0);
	cout << ans1 % mod << '\n';
	return 0;
}

