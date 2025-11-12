#include <bits/stdc++.h>
using namespace std;
int n, m;
int seat;
int a[110];
int r;
int sum;
int aaa, bbb;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	seat = n * m;
	for (int i = 1; i <= seat; i++) {
		cin >> a[i];
		r = a[1];
	}
	sort(a + 1, a  + 1 + seat);
	for (int i = seat; i >= 1; i--) {
		if (a[i] != r) {
			sum++;
		} else {
			sum++;
			break;
		}
	}
	if (sum <= m) {
		cout << 1 << " " << sum;
		return 0;
	}
	if (sum > m) {
		if (sum / m != 0) {
			aaa = (sum / m) + 1;
		} else {
			aaa = sum / m;
		}
		if (aaa % 2 == 1) {
			bbb = m - ((aaa *m) % sum);
			cout << aaa << " " << bbb;
			return 0;
		}
		if (aaa % 2 == 0) {
			bbb = (m + 1) - ((aaa *m) - sum);
			cout << aaa << " " << bbb;
			return 0;
		}
	}
	return 0;
}
