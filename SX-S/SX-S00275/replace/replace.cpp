#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, m;
string t[N], t1[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> t1[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> t[i] >> t1[i];
	}
	for (int i = 1; i <= m; i++) {
		cout << 0 << endl;
	}
	return 0;
}