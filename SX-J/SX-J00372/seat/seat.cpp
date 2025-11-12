#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	int id, val;
} arr[1005];

bool cmp(node a, node b) {
	return a.val > b.val;
}
int x, y, z;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i].val;
		arr[i].id = i;
	}
	sort(arr + 1, arr + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (arr[i].id == 1) {
			z = i;
		}
	}
	x = (z + n - 1) / n;
	int k = z % n;
	if (k == 1) {
		if (x % 2) {
			cout << x << ' ' << 1;
		} else
			cout << x << ' ' << n;
	} else if (k) {
		if (x % 2) {
			cout << x << ' ' << k;
		} else
			cout << x << ' ' << n - k + 1;
	} else {
		if (x % 2) {

			cout << x << ' ' << n;
		} else
			cout << x << ' ' << 1;
	}

	return 0;
}
