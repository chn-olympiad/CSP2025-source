#include <bits/stdc++.h>
using namespace std;
int n, k, a[1005];
int sum = 0;
int mp[1005][1005];
int mmp[1005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mp[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int p = a[i];
		mp[i][i] = p;
		for (int j = i + 1; j <= n; j++) {
			p ^= a[j];
			mp[i][j] = p;
		}
	}
	/*	for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				cout << mp[i][j] << " ";
			}
			cout << endl;
		}*/

	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (mp[i][j] != INT_MAX) {
				if (mp[i][j] == k && (mmp[i] != 1)) {
					sum++;
					//cout << i << " " << j << endl;
					for (int p = 0; p <= j; p++) {
						mmp[p] = 1;
					}
				}
			}
		}
	}
	cout << sum;
	return 0;

}
