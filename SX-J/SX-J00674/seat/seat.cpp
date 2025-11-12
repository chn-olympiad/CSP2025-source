#include <bits/stdc++.h>
using namespace std;
long long a[100005];

bool cmp(int x, int y) {
	return	x > y;
}

int main() {
	//freopen("seat.in","r","stdin");
	//freopen("seat.out","w","stdout");
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1, a + n + 1, cmp);
	int q;
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == r) {
			q = i;
		}
	}
	int c, x;
	c = q / n;
	if (q % n == 0)
		x = n;
	else
		x = q % n;
	cout << c << " " << x;
	return 0;
}