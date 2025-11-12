#include <bits/stdc++.h>
using namespace std;
int n, a[5005], cnt;
int aaa(int l1, int l2) {
	int sum = 1;
	for (int i = 1; i <= l2; i++) {
		sum *= l1;
	}
	return sum;
}

int sss(int dangqian) {
	if (dangqian == 2) {
		return 0;
	}
	if (dangqian == 3) {
		return 1;
	}
	return sss(dangqian - 1) + sss(dangqian - 2) + aaa(3, dangqian - 3) + 1;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		int maxm = -1;
		maxm = max(max(a[0], a[1]), a[2]);
		if ((a[0] + a[1] + a[2]) > 2 * maxm) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << sss(n);
	}
	return 0;
}
