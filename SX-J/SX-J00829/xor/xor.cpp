#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int b[N][30];
int n, k;

void build() {
	for (int i = 1; i <= n; i++) {
		b[i][0] = a[i];
	}
	for (int i = 1; i <= 22; i++) {
		if ((1 << i) > n)
			break;
		for (int j = 1; j <= n; j++) {
			b[j][i] = (b[j][i - 1] ^ b[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int query(int l, int r) {
	int ans = 0;
	while (l <= r) {
		int ss = 0;
		while (1) {
			if (l + (1 << ss) - 1 <= r) {
				ss++;
			} else {
				ss--;
				break;
			}
		}
		ans = ans ^b[l][ss];
//		cout << ans << " " << ss << " " << l << " " << b[l][ss] << endl;
		l = l + (1 << ss) ;
//		cout << l << " " << ss << endl;
	}

	return ans;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build();
	vector<pair<int, int> > v;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j <= 10; j++) {
//			int sum = 0;
//			for (int mm = i; mm <= (i + (1 << (j)) - 1); mm++) {
//				sum = sum ^a[mm];
//			}
//			cout << i << " " << j << " " << sum << " " << b[i][j] << "\n";
//		}
//		cout << endl;
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int aaa = query(i, j);
//			cout << i << " " << j << ": " << aaa << endl;
			if (aaa == k) {
				v.push_back({j, i});
				break;
			}
		}
	}
	sort(v.begin(), v.end());
	int R = 0, ans = 0;
	int nn = v.size();
	for (int i = 0; i < nn; i++) {
		if (v[i].second > R) {
			ans++;
			R = v[i].first ;
		}
	}
	cout << ans << endl;
	return 0;
}
