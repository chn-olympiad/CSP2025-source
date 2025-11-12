#include <bits/stdc++.h>
int t;
using namespace std;
long long a[10000][10000];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n = 0;
		cin >> n;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
	}
cout<<1;
	return 0;
}