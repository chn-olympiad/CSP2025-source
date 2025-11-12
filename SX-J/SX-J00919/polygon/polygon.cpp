#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
int a[5005], b[5005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int sum = 0, top = 1;
		memset(b, 0, sizeof b);
		for (int j = 3; j <= n; j++) {
			sum += a[j];
			b[top] = a[j];
			top++;
		}
		sort(b + 1, b + top + 1, cmp);
		if (sum > b[top]) {
			cnt++;
		}
	}
	cout << cnt % M;


	return 0;
}