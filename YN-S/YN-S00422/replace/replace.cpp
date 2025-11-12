#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	cin >> n >> m;
	if (m % 2 == 0) {
		for (int i = 1; i <= m; i++) {
			cout << 0 << endl;
		}
	} else {
		for (int i = 1; i <= m; i++) {
			cout << 1;
		}
	}
	return 0;
}