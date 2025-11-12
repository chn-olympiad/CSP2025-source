#include <bits/stdc++.h>
using namespace std;

#define my_sort(zzz) sort(zzz+1,zzz+1+n,greater<int>())

const int N = 1e5 + 5;
int t;
int n;
int x[N], y[N], z[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool f = false, f1 = false;
		for (int i = 1; i <= n; i++) {
//			cin >> x[i] >> y[i] >> z[i];
			cin >> x[i] >> y[i] >> z[i];
			if (y[i] != 0 && z[i] != 0) {
				f = true;
			}
		}
		if (!f) {
			sort(x + 1, x + 1 + n, greater<int>());
			long long ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += x[i];
			}
			cout << ans << "\n";
			continue;
		}
		my_sort(x), my_sort(y), my_sort(z);
		vector <int>  v;
		for (int j = 1; j <= n / 2; j++) {
			v.push_back(x[j]);
			v.push_back(y[j]);
			v.push_back(z[j]);
		}
		sort(v.begin(), v.end(), greater<int>());
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += v[i - 1];
		}
		cout << ans << "\n";
	}
	return 0;
}
