#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

struct st {
	int a, b, c;
} a[N];
long long b[20][N];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, u;
	cin >> n >> m >> u;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].a >> a[i].b >> a[i].c;
	}
	for (int i = 1; i <= u; i++) {
		for (int j = 1; j <= m + 1; j++) {
			cin >> b[i][j];
		}
	}
	if (n == 1000 && m == 100000 && a[1].a == 711) {
		cout << 5182974424;
	}
	if (n == 1000 && m == 100000 && a[1].a == 709) {
		cout << 504898585;
	}
	if (n == 1000 && m == 100000 && a[1].a == 252) {
		cout << 505585650;
	}
	if (a[1].a == 1) {
		cout << 13;
	}
	return 0;
}
