#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;

struct node {
	int c;
	bool f = false;
} a[501];

bool cmp(node x, node y) {
	return x.c < y.c;
}

long long jc(int y) {
	long long x = 1;
	for (int i = 2; i <= y; i++) {
		x = x * i % 998244353;
	}
	return x;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].c;
	}
	if (m == 1) {
		cout << jc(n);
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	int x = 0;
	for (int i = 1; i <= m; i++) {
		if (a[i].c > 0 && s[x] == '1') {
			x++;
			a[i].f = true;
		}
		if (x == m)
			break;
		for (int j = 1; j <= n; j++) {
			a[j].c--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].c <= 0 && a[i].f == false)
			n--;
	}
	cout << jc(n);

	return 0;
}
