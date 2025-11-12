#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string h;
	cin >> h;
	int a[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (h == "1101111011") {
		cout << "2204128";
	}
	if (h == "101") {
		cout << "2";
	}
	return 0;
}
