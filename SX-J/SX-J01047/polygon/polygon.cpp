#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[5005], ans;
bool b[5005];
bool f1;
const int mod = 998244353;

void fs(int len, int mx, int num, int x) {
	if (len >= 3 && mx * 2 < num) {
		ans++;
		ans %= mod;
	}
	for (int i = min(x, n); i >= 1; i--) {
		if (!b[i]) {
			b[i] = 1;
			fs(len + 1, max(mx, a[i]), num + a[i], i);
			b[i] = 0;
		}
	}
	return ;
}

int C(int m, int n) {
	int num = 1;
	for (int i = n - m + 1; i < n; i++)
		num = num * i;
	return num;
}

//n xuan m wei C(,n)
signed main() {
	freopen("polygon.in", "r", stdin), freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)
			f1 = 1;
	}
	if (!f1) {
		for (int i = 3; i <= n; i++)
			ans = (ans + C(n - i + 1, n)) % mod/*, cout << C(n - i + 1, n) << "\n"*/;
		cout << ans;
//		cout << " " << C(3, 5);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		b[i] = 1;
		fs(1, a[i], a[i], i);
		b[i] = 0;
	}
	cout << ans;
	//64pts
	return 0;
}
