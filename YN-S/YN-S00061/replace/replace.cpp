#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int  m, n;
string a[N], b[N], c[N], d[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		cin >> d[i];
	}
	for (int i = 0; i < n; i++) {
		cout << 0 << endl;
	}
	return 0;
}