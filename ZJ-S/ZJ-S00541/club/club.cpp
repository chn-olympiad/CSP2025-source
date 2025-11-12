#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5;
struct Node {
	int pos[4], val[4];
}a[N];

bool Cmp(Node x, Node y) {
	return x.val[1] - x.val[2] < y.val[1] - y.val[2];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, mx = 0, mp, sum = 0, b[4] = {0, 0, 0, 0};
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i].val[j];
				a[i].pos[j] = j;
			}
			if (a[i].val[1] < a[i].val[2]) {
				swap(a[i].val[1], a[i].val[2]);
				swap(a[i].pos[1], a[i].pos[2]);
			}
			if (a[i].val[2] < a[i].val[3]) {
				swap(a[i].val[2], a[i].val[3]);
				swap(a[i].pos[2], a[i].pos[3]);
			}
			if (a[i].val[1] < a[i].val[2]) {
				swap(a[i].val[1], a[i].val[2]);
				swap(a[i].pos[1], a[i].pos[2]);
			}
			b[a[i].pos[1]]++;
			sum += a[i].val[1];
		}
		sort(a + 1, a + n + 1, Cmp);
		for (int i = 1; i <= 3; i++) {
			if (b[i] > mx) {
				mx = b[i];
				mp = i;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (mx <= n / 2) break;
			if (a[i].pos[1] == mp) {
				mx--;
				sum -= (a[i].val[1] - a[i].val[2]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}