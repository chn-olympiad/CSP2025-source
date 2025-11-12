#include <bits/stdc++.h>
using namespace std;
long long t, n, a[100005], b[100005], c[100005], mmax[100005], mmin[100005], mmid[100005];
long long a1[10], b1[10], c1[10], sum;
long long cha[100005], f;

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j] >> b[j] >> c[j];
			mmax[j] = max(a[j], b[j]);
			mmax[j] = max(mmax[j], c[j]);
			mmin[j] = min(a[j], b[j]);
			mmin[j] = min(mmin[j], c[j]);
			mmid[j] = a[j] + b[j] + c[j] - mmax[j] - mmin[j];
			cha[j] = mmax[j] - mmid[j];
			if (mmax[j] == a[j]) {
				a1[i]++;
			}
			if (mmax[j] == b[j]) {
				b1[i]++;
			}
			if (mmax[j] == c[j]) {
				c1[i]++;
			}
		}
		sort(cha + 1, cha + n + 1);
		for (int j = 1; j <= n; j++) {
			sum += mmax[j];
		}
		if (a1[i] <= n / 2 and b1[i] <= n / 2 and c1[i] <= n / 2) {
			cout << sum << "\n";
		} else {
			if (a1[i] > n / 2) {
				f = f + a1[i] - n / 2;
			}
			if (b1[i] > n / 2) {
				f = f + b1[i] - n / 2;
			}
			if (c1[i] > n / 2) {
				f = f + c1[i] - n / 2;
			}
			for (int j = 1; j <= f; j++) {
				sum = sum - cha[j];
			}
			cout << sum << "\n";
		}
		sum = 0;
		f = 0;
		for (int j = 1; j <= n; j++) {
			mmax[j] = 0;
			mmin[j] = 0;
			mmid[j] = 0;
			cha[j] = 0;
		}
	}


	return 0;
}
