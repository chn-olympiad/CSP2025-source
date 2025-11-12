#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
string s;
const int S = 10000;
int a[S];
int n;

signed main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	if (n < 3) {
		cout << "0";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

		}
	}
	return 0;
}
