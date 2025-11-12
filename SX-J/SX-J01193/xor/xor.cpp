#include <bits/stdc++.h>
using namespace std;
long long a[500001];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, ans = 0;
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			long long sum = 0;
			for (int l = i; l <= j; l++) {
				sum = sum ^a[l];
			}
			if (sum == k) {
				i = j;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
