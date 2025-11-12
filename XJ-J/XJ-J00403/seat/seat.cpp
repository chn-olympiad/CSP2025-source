#include<bits/stdc++.h>

using namespace std;

int a[110], b[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n*m; i++) cin >> b[i];
	int idx, s = b[0];
	sort(b, b+n*m);
	for (int i = 0; i < n*m; i++) {
		a[i] = b[n*m-i-1];
	}
	for (int i = 0; i < n*m; i++) {
		if (a[i] == s) {
			idx = i + 1;
			break;
		}
	}
	
	int r = idx % n;
	if (r == 0) r = n;
	int c = idx / n + 1;
	if (r == n) {
		c --;
	}
	if (c % 2 == 0) r = n - r + 1;
	cout << c << " " << r << endl;

	
	return 0;
}
