#include <bits/stdc++.h>
#define N 10005
using namespace std;
int n, m;

struct zw {
	int k, id;
} a[N];

bool cmp(zw x, zw y) {
	return x.k > y.k;
}

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	cout << "Hi word\n";

	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].k ;
	}
	a[1].id = 1;
	sort(a + 1, a + n *m + 1, cmp)	;

	int id = 0;
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1)
			id = i;
	}
	cout << (id - 1) / n + 1 << " ";
	if (((id - 1) / n + 1) % 2 == 0) {
		cout << n - ((id - 1) % n + 1) + 1;
	}


	else
		cout << ((id - 1) % n + 1);

	return 0;
}














