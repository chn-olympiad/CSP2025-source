#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define reg(i, x, y, step) for (int i = x; i <= y; i += step)
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e3 + 10;
const int Mod = 998244353;
int a[N], cho[N], ans = 0, num[N];
bool vis[N];
int n;
void dfs(int cur) {
	if (cur > n + 1) return ;
	if (cur >= 3) {
		int sum = 0, Max = INT_MIN;
		for (int i = 1; i < cur; i++) sum += cho[i], Max = max(Max, cho[i]);
		if (sum > 2 * Max) {
			//for (int i = 1; i < cur; i++) cout << cho[i] << " ";
			//cout << endl;
			ans++;
			ans %= Mod;
		}
	}
	for (int i = cur; i <= n; i++) {
		if (!vis[i] && a[i] >= cho[cur - 1]) {
			vis[i] = 1;
			cho[cur] = a[i];
			dfs(cur + 1);
			vis[i] = 0;
		}
	}
}
signed main() {
	File("polygon");
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
