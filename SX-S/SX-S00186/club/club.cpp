#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+10;
ll T, n, arr[5], mn1[5], brr[5];

struct lk {
	ll a, b, c;
	ll gg[5];
	ll mx, cmx, mn, sum;
} q[N];


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(brr, 0, sizeof(brr));
		memset(mn1, 0, sizeof(mn1));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> q[i].a >> q[i].b >> q[i].c;
			arr[1] = q[i].gg[1] = q[i].a, arr[2] = q[i].gg[2] = q[i].b, arr[3] = q[i].gg[3] = q[i].c;
			sort(arr + 1, arr + 3 + 1);
			if (arr[2] == q[i].a)
				q[i].cmx = 1;
			else if (arr[2] == q[i].b)
				q[i].cmx = 2;
			else if (arr[2] == q[i].c)
				q[i].cmx = 3;
			if (arr[3] == q[i].a)
				q[i].mx = 1;
			else if (arr[3] == q[i].b)
				q[i].mx = 2;
			else if (arr[3] == q[i].c)
				q[i].mx = 3;
		}
		for (int i = 1; i <= n; i++) {
			if (mn1[q[i].mx] + 1 <= n / 2)
				brr[q[i].mx] += q[i].gg[q[i].mx];
			else
				brr[q[i].cmx] += q[i].gg[q[i].cmx];
		}
		cout << brr[1] + brr[2] + brr[3] << endl;
	}
	return 0;
}
