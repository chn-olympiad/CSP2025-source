#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int sum = 0;
	int n;
	cin >> n;
	int a[n + 3];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 1, r = 3;
	if (n == 3) {
		int b = 0;
		int sum1 = 0;
		for (int j = 1; j <= 3; j++) {

			sum1 += a[j];
			if (b < a[j])
				b = a[j];
		}
		if (sum1 > b * 2)
			cout << 1;
		else
			cout << 0;
	}
	if (n == 4) {
		for (int i = 1;; i++) {
			int sum1 = 0;
			int b = 0;
			for (int j = l; j <= r; j++) {
				sum1 += a[j];
				if (b < a[j])
					b = a[j];
			}
			if (sum1 > b * 2) {
				sum++;

			}
			if (r < n)
				r++;
			else if (l < n - 2) {
				l++;
				r = l + 2;
			} else
				break;
			if (a[1] + a[2] + a[4] > max(a[1], max(a[2], a[4])) * 2)
				sum++;
			if (a[1] + a[3] + a[4] > max(a[1], max(a[3], a[4])) * 2)
				sum++;
			cout << sum;
		}
//		int yi=0;
//		for(int i=1;i<=n;i++){
//			if(a[i]==1) yi++;
//		}
//		if(yi==n){
//
//		}
//	}

		return 0;

	}
}
