#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	if (m == 1) {
		cout << n;
	} else if (m == n) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
