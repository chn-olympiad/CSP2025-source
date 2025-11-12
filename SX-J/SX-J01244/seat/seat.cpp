#include <bits/stdc++.h>
using namespace std;
int n, m, a[10005], s, cnt, cntn = 1, cntm;

int main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m ;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	s = a[1];
	sort(a + 1, a + n *m + 1);
	for (int i = n * m; i >= 1; i--) {
		cnt++;
		if (cnt % n == 1) {
			cntm++;
		} else {
			if (cntm % 2 == 1)
				cntn++;
			else
				cntn--;
		}
		if (a[i] == s) {
			cout << cntm << " " << cntn;
			return 0;
		}
	}

	return 0;

}
