#include <bits/stdc++.h>
using namespace std;
int a[100000], n, s = 0, k = 0;

int main() {

	freopen('polygon.in','r',stdin);
	freopen('polygon.out','w',stdout);
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			int u = j;
			int max = INT_MIN;
			int s = 0;
			while (u != 0) {
				if (max < a[u]) {
					max = a[u];
				}
				s = s + a[u];
				u--;


			}
			if (s > 2 * max) {
				k++;
			}
		}
	}
	cout << k / 2;
	return 0;

}
