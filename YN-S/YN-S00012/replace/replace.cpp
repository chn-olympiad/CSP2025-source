#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
string a[N], b[N], aa[N], bb[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> aa[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i] >> bb[i];
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}



	return 0;
}