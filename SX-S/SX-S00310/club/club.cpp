#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10005][3];
ll n, t;
ll f[50000], s, e[50000];
int vis[100000];

void guocheng() {
	f[n / 2] = 0;
	memset(e, 0, sizeof(e));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n / 2; j++) {

			for (int k = 0; k < n; k++)
				f[j] = max(f[j], f[j - 1] + a[k][i]);
//				if (vis[k] == 0)
//					if (f[j] < f[j - 1] + a[k][i]) {
//						f[j] = f[j - 1] + a[k][i];
//						memset(vis, 0, sizeof(vis));
//						vis[k] = 1;
//					}

		}

	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	n = 0;
	t = 0;
	memset(a, 0, sizeof(a));

//	cin >> t;
//	while (t--) {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	guocheng();
//	}
	cout << f[n / 2];
	return 0;
}
