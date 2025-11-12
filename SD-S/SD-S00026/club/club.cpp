#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], b[N], c[N];
void solve() {
	cin >> n;
	bool f1 = 1, f2 = 1, f3 = 1;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i] >> b[i] >> c[i];
		if(a[i] != 0) f3 = 0;
		if(b[i] != 0) f1 = 0;
		if(c[i] != 0) f2 = 0;
	}
	if((f1 && f2) || (f1 && f3) || (f2 && f3)) {
		if(f1 && f2) sort(a + 1, a + n + 1);
		else if(f1 && f3) sort(c + 1, c + n + 1);
		else sort(b + 1, b + n + 1);
		long long ans = 0;
		for(int i = n / 2 + 1; i <= n; ++ i) {
			ans += ((f1 && f2) ? a[i] : 0);
			ans += ((f3 && f2) ? b[i] : 0);
			ans += ((f1 && f3) ? c[i] : 0);
		}
		cout << ans << "\n";
		return ;
	}
	else if(f2 || f1 || f3) {
		if(f2) {
			sort(a + 1, a + n + 1);
			sort(b + 1, b + n + 1);	
		}
		else if(f3) {
			sort(c + 1, a + n + 1);
			sort(b + 1, b + n + 1);
		}
		else {
			sort(a + 1, a + n + 1);
			sort(c + 1, b + n + 1);
		}
		long long ans = 0;
		for(int i = n / 2 + 1; i <= n; ++ i) {
			if(f2) ans += max(a[i], b[i]);
			else if(f3) ans += max(b[i], c[i]);
			else ans += max(a[i], c[i]);
		}
		cout << ans << "\n";
		return ;
	}
	if(n == 2) {
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		sort(c + 1, c + n + 1);
		long long ans = 0;
		ans += max(a[1], max(b[1], c[1]));
		int d;
		if(a[2] > b[2] && a[2] > c[2]) d = a[2], a[2] = -1;
		else if(c[2] > b[2] && c[2] > a[2]) d = c[2], c[2] = -1;
		else if(b[2] > a[2] && b[2] > c[2]) d = b[2], b[2] = -1;
		ans += max(a[2], max(b[2], c[2]));
		if(ans < d) ans = d;
		cout << ans << "\n";
	}
	else {
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		sort(c + 1, c + n + 1);
		long long ans = 0;
		int len = n - n / 3;
		for(int i = len + 1; i <= n; ++ i)
			ans += (a[i] + b[i] + c[i]);
		if(n % 3 == 1) ans += max(a[len], max(b[len], c[len]));
		else {
			if(b[len] > c[len] && a[len] > c[len]) ans += (b[len] + a[len]);
			else if(b[len] > a[len] && c[len] > a[len]) ans += (b[len] + c[len]);
			else if(a[len] > b[len] && a[len] > c[len]) ans += (c[len] + a[len]);
		}
		cout << ans << "\n";
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T --) solve();
	return 0;
}
