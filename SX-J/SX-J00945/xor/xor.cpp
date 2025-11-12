#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5+10;
long long n, k, f = 1, cnt, sum, j;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			f = 0;
			cnt++;
			j = 0;
		} else {
			if (a[i] == 1) {
				j++;
				if (j % 2 == 0) {
					sum++;
				}
			}
		}
	}
	if (f == 1) {
		if (k == 1) {
			cout << n;
		} else {
			if (k == 0) {
				cout << sum;
			} else {
				cout << 0;
			}
		}
	} else {
		if (k == 1) {
			cout << n - cnt;
		} else {
			if (k == 0) {
				cout << cnt + sum ;
			} else {
				cout << 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
