#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t, sum;
int a[N][3];
int amax[N];

int main() {
//	freopen("club.in", 'r', stdin);
//	freopen("club.out", 'w', stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			amax[i] = INT_MIN;
			for (int j = 1; j <= 3; j++) {
				amax[i] = max(amax[i], a[i][j]);
			}
			sum += amax[i];
		}
		cout << sum << '\n';
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}