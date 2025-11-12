#include <bits/stdc++.h>
using namespace std;
int  n, t, s = 0;
int a[100005], b[100005][4];

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t >> n;
	for (int k = 1; k <= t; k++) {
		for (int  i = 1; i <= n; i++) {
			cin >> a[i] >> b[i][2] >> b[i][3];
		}
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		for (int  i = 1; i <= n / 2; i++) {
			s += a[i];
		}
		cout << s;
		return 0;
	}

}














































