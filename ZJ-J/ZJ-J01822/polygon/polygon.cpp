#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += d)
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= d)
//#define int long long
void INIT() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAXN = 5e3 + 10, MOD = 998244353;
int n;
int a[MAXN];
ll ans = 0;

void DFS(int deep, int _max, int sum, int cnt) {
	if(deep == n + 1) {
		if(sum > _max * 2 && cnt >= 3)
			ans = (ans + 1) % MOD; 
		return;
	}
	
	DFS(deep + 1, max(a[deep], _max), sum + a[deep], cnt + 1);
	DFS(deep + 1, _max, sum, cnt);
}

signed main() {
	INIT();
	
	cin >> n;
	bool tMAX = 1;
	upl(i, 1, n, 1) {
		cin >> a[i];
		tMAX &= a[i] == 1;
	}
	if(tMAX) {
		ans = 1;
		upl(i, 1, n, 1)
			ans = ans * 2 % MOD;
		cout << (ans - 1 - n - n * 1ll * (n - 1) / 2 + MOD) % MOD;
		return 0;
	}
	
	DFS(1, 0, 0, 0);
	cout << ans;
	return 0;
}

