#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

int main() {
	//freopen(numbee.in,"r",stdin);
	//freopen(number.out,"w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (a[i + 1] > a[i]) {
			a[i] = a[i + 1];
		}
		cout << a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i = n) {


			}
		}
	}
	return 0;
}