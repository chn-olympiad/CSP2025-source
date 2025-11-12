#include <bits/stdc++.h>
using namespace std;

struct node {
	int v, id;
} a[1000];

bool cmp(node f, node b) {
	return f.v > b.v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].v;
		a[i].id = i;
	}
	sort(a + 1, a + n *m + 1, cmp);
	int pos = 1;
	for (int i = 1; i <= n * m; i++) {
//		cout << a[i].v << ' ';
		if (a[i].id == 1) {
			pos = i;
			break;
		}
	}
//	cout << pos << endl;
//	cin >> pos;
	int c = pos % n == 0 ? pos / n : pos / n + 1;
	int tmp = (pos % n) == 0 ? ((pos % n) + n) : (pos % n) ;
//	cout << tmp;
	int r = (c & 1) ? tmp : n - tmp + 1;
	cout << c << ' ' << r;
	return 0;
}
