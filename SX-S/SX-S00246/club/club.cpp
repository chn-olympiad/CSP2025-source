#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int  cnt[10005], a[10005][3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, k[1005], s = 0, maxi;
	cin >> t >> n;
	while (t--) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] > a[i][2])
				maxi = a[i][1];
			else
				maxi = a[i][2];
			if (maxi < a[i][3])
				k[i] = a[i][3];
			else
				k[i] = maxi;
		}
	}
	while (t--) {
		for (int i = 1; i <= n; i++) {
			s = s + k[i];
		}
		cout << s << endl;
	}


	return 0;
}

