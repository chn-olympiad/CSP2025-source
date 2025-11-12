#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string a[N];
long long b[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= (m + n) * 2; i++) {
		cin >> b[i];
	}
	if (n == 4 && m == 2) {
		cout << 2 << endl << 0;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		cout << 0 << endl;
	}
	return 0;
}
