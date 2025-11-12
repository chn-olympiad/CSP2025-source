#include <bits/stdc++.h>
using namespace std;
long long n, k;
int a[500005];

struct node {
	int l, r;
} edge[500005];
bool f, flag[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			cnt++;
			flag[i] = 1;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = a[i];
		if (flag[i] == 1) {
			continue;
		}
		for (int j = i + 1; j <= n; j++) {
			ans ^= a[j];
			if (ans == k) {
				f = 1;
				for (int K = i; K <= j; K++) {
					if (flag[K] == 1) {
						f = 0;
						break;
					}
				}
				if (f)
					cnt++;
				for (int K = i; K <= j; K++) {
					flag[K] = 1;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
