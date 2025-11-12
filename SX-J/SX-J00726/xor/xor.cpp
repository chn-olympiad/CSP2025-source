#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int a[500005];

bool pd(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int sum = a[i];
		if (a[i] == k) {
			cnt++;
			continue;
		}
//		cout << cnt << endl;
		if (cnt == x) {
//			cout << 111111111111122222 << endl;
			return 1;
		}
		for (int j = i + 1 ; j <= n; j++) {
//			cout << 99 << endl;
			if (sum == k) {
				cnt++;
				i = j + 1;
//				cout << k << endl;
				cout << sum << " ," << a[j] << " " << sum << endl;
//				cout << 11111111 << endl;
				break;
			}
			sum  = sum xor a[j];
			cout << sum << " ," << a[j] << " " << sum << endl;

		}
	}
	return 0;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1, r = n;
	while (r > l) {
		int mid = (l + r + 1 ) / 2;
		if (pd(mid) == 1) {
			l = mid ;
		} else {
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}