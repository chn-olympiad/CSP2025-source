#include "bits/stdc++.h"
using namespace std;
int t, j, num;
long long n, a[20005][4], sum;

int main() {
	freopen("club1.in", "r", stdin);
	freopen("club1.out", "w", stdout);
	cin >> t;
	for (int o = 1; o <= t; o++) {
		cin >> n;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];// ‰»Î
			sum += max(a[i][1], max(a[i][2], a[i][3]));
		}
		cout << sum << endl;
	}
}