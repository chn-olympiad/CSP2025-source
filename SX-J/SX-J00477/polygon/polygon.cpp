#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int a[N];
int n;
int nm;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		nm += a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	if (nm <= 2 * a[1]) {
		cout << 0;
		return 0;
	} else {
		cout << 1;
		return 0;
	}
	return 0;
}
