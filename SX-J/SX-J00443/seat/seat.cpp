#include <bits/stdc++.h>
using namespace std;
#define N 110
#define ll long long
ll a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ll n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	k = a[1];

	sort(a + 1, a + n *m + 1, cmp);


	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			//cout << i << " ";
			ll b = (i - 1) / n + 1;
			ll c = i - n * (b - 1) ;
			//cout << b *(n - 1) << endl;
			if (b % 2 != 0) {
				cout << b << " " << c;
			} else
				cout << b << " " << m - c + 1;
			return 0;
		}
	}
	return 0;
}
