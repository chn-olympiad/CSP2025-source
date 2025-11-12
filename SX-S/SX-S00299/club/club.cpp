#include <bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005];
int t, n, tn;

long long e(int a, int n1, int n2, int n3) {
	long long w1 = 0, w2 = 0, w3 = 0;
	if (a > n)
		return 0;
	if (n1 <= tn)
		w1 = e(a + 1, n1 + 1, n2, n3) + a1[a];
	if (n2 <= tn)
		w2 = e(a + 1, n1, n2 + 1, n3) + a2[a];
	if (n3 <= tn)
		w3 = e(a + 1, n1, n2, n3 + 1) + a3[a];
	return max(w1, max(w2, w3));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		while (n--)
			a1[n] = a2[n] = a3[n] = 0;
		cin >> n;
		tn = n / 2;
		for (int i = 1; i <= n; ++i) {
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		cout << e(1, 1, 1, 1) << endl;
	}
	return 0;
}
