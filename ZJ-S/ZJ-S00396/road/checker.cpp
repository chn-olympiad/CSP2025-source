#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {

	int cnt = 0;
	while (1) {
		system("./gen");
		system("./road");
		system("./BF");
		if (system("diff road.ans road.out -Z")) {
			return 0;
		}
		// cout << '#' << ++cnt << '\n';
	}
	return 0;
}