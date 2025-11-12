#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[5005], sum, cnt, pop, id;
double x;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			id++;
			sum += a[j];
			x = sum / 2 * 1.0;
			pop = floor(x);
			if (pop >= id && id >= 3) {
				//cout << id << " " << pop << " " << sum << endl;
				cnt++;
			}
		}
		id = 0;
	}
	cout << cnt;
	return 0;
}
