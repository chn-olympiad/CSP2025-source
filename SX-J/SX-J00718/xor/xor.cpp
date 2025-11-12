#include <bits/stdc++.h>
using namespace std;
long long n, k, a[600000], ans, b[600000];

bool dg(int x) {
	long long box1 = 0, box;
	for (int i = 1; i <= n; i++) {
		box = box ^a[i];
		if (box == k) {
			box1++;
			box = 0;
		}
	}
	if (box1 >= x) {
		return 1;
	} else
		return 0;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = n;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (dg(mid) == 1) {
			ans = mid, l = mid + 1;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
