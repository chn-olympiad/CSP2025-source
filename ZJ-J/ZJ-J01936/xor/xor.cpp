#include <bits/stdc++.h>
using namespace std;

int a[500010];
int sum[500010];
int n, k;

int main() {
	freopen("xor.in", "r",stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int pos = 1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = pos; j <= i; j++) {
			if ((sum[i] ^ sum[j - 1]) == k) {
				cnt++;
				pos = i + 1;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}

