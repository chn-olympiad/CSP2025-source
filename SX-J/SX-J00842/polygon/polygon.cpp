#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dou double
#define str string

//AC_tgoyyx

const ll N = 1e6;

int a[5010];
int n, ans = 0;

void dfs(int si, int k, int l, int ml) {
	if (si == n - 1 && k >= 3 && l > ml * 2) {
		ans = (ans + 1) % 998244353;
		return ;
	}
	dfs(si + 1, k + 1, l + a[si], max(ml, a[si]));

	dfs(si + 1, k, l, ml);

}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	dfs(0, 0, 0, 0);

	cout << ans;

	return 0;
}
