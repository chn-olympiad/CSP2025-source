#include <bits/stdc++.h>
using namespace std;
int a[100005];

int main() {
	//freopen("seat.in", "r", in);
	//freopen("seat.out", "w", out);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i];
		}

	}
	sort( a + n + 1, a + 1 );
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}