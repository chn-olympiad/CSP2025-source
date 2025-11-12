#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long a[N][5], pre[5];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		long long num = 0;
		for (int i = 1; i <= n; i++) {
			long long mx = max(a[i][1], max(a[i][2], a[i][3]));
			if (mx == a[i][1]) {
				pre[1]++;
			} else if (mx == a[i][2]) {
				pre[2]++;
			} else {
				pre[3]++;
			}
			num += mx;
		}
		long long mn = 2e9, h = 0, h2 = 0;
		if (pre[1] > n / 2) {
			for (int i = 1; i <= pre[1] - n / 2; i++) {
				for (int j = 1; j <= n; j++) {
					if (mn > a[j][1] - a[j][2]) {
						mn = a[j][1] - a[j][2];
						h = 2;
						h2 = j;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (mn > a[j][1] - a[j][3]) {
						mn = a[j][1] - a[j][3];
						h = 3;
						h2 = j;
					}
				}
				num -= mn;
				pre[1]--;
				pre[h]++;
				a[h2][2] = -1;
				a[h2][3] = -1;
			}
		} else if (pre[2] > n / 2) {
			long long sum = pre[2] - n / 2;
			for (int i = 1; i <= sum; i++) {
				for (int j = 1; j <= n; j++) {
					if (mn > a[j][2] - a[j][1]) {
						mn = a[j][2] - a[j][1];
						h = 1;
						h2 = j;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (mn > a[j][2] - a[j][3]) {
						mn = a[j][2] - a[j][3];
						h = 3;
						h2 = j;
					}
				}
				num -= mn;
				pre[2]--;
				pre[h]++;
				a[h2][1] = -1;
				a[h2][3] = -1;
			}
		} else if (pre[3] > n / 2) {
			for (int i = 1; i <= pre[3] - n / 2; i++) {
				for (int j = 1; j <= n; j++) {
					if (mn > a[j][3] - a[j][1]) {
						mn = a[j][3] - a[j][1];
						h = 1;
						h2 = j;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (mn > a[j][3] - a[j][2]) {
						mn = a[j][3] - a[j][2];
						h = 2;
						h2 = j;
					}
				}
				num -= mn;
				pre[3]--;
				pre[h]++;
				a[h2][1] = -1;
				a[h2][2] = -1;
			}
		}
		cout << num << '\n';
		pre[1] = 0;
		pre[2] = 0;
		pre[3] = 0;
	}
}