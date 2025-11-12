#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, l[N], sm, mx;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sm += l[i].mx = max(mx, l[i]);
	}
	if (m <= 3) {
		if (sm > mx * 2) {
			cout << sm;
		}
	}

}
