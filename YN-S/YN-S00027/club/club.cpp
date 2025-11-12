#include <bits/stdc++.h>
using namespace std;
int a[100005][3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			sum += max(max(a[i][1], a[i][2]), a[i][3]);
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}