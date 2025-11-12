#include <bits/stdc++.h>
using namespace std;
int a[105], n, m, id, f;

bool cmp(int c, int b) {
	return c > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	f = n * m;
	for (int i = 1; i <= f; i++)
		cin >> a[i];
	id = a[1];
	sort(a + 1, a + f + 1, cmp);
	for (int i = 1; i <= f; i++)
		if (id == a[i]) {
			id = i;
			break;
		}
	int v = a % b, u = (int)((id - 0.5) / n) + 1;
	cout << u << " ";
	if (u % 2 == 0) {
		if (n - v + 1 > n)
			cout << n - v + 1 - n;
		else
			cout << n - v + 1 ;
		return 0;
	} else {
		if (v == 0)
			cout << n ;
		else
			cout << v;
		return 0;
	}

}
