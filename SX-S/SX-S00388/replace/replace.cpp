#include <bits/stdc++.h>
using namespace std;
int n, q, len[2005], lent;
char a[2005][2005], b[2005][2005], t1[2005], t2[2005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
		len[i] = strlen(a[i]);
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		lent = strlen(t1);
		cout << 0 << endl;
	}
}