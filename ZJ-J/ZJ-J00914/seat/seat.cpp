#include <bits/stdc++.h>
using namespace std;
int n, m, num[200], sc, k;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
		
	cin >> n >> m;
	int cur = n * m;
	for (int i = 1; i <= cur; i++) {
		scanf("%d", &num[i]);
	}
	sc = num[1];
	sort (num + 1, num + cur + 1, cmp);
	for (int i = 1; i <= cur; i++) {
		if (num[i] == sc) {
			k = i;
			break;
		}
	}
	
	if (k / n * n == k) {
		cout << k / n << ' ';
		if ((k / n) % 2 == 1) cout << n;
		else cout << 1;
	}
	else if ((k / n) % 2 == 0) {
		cout << k / n + 1 << ' ';
		cout << k - k / n * n;
	}
	else {
		cout << k / n + 1;
		cout << ' ' << 1 + n - (k - k / n * n);
	}
	return 0;
}

