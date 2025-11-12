#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int b;
int cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		b = a[1];
	}
}
sort(a + 1, a + n *m + 1, cmp);

for (int i = 1; i <= n * m; i++) {
	if (b == a[1]) {
		cout << "1 1";
	} else {
		if (b == a[i]) {
			cout << 1 << 1 + (i - 1);
		}
	}
}
return 0;
}
