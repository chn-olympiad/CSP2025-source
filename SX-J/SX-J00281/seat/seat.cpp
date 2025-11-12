#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a[105];
	cin >> n >> m;
	for (int i = 0; i <= n * m; i++) {
		cin >> a[i];
		if (m == 1 && n == 1) {
			cout << "1" << " " << "1";
			return 0;
		}
	}


	return 0;
}