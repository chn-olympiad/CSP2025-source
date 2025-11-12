#include <bits/stdc++.h>
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
int a[500005];

int main() {
	NOI("xor");
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		if (k == a[1])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (n == 2 and k == 0) {
		int ans = 0, ans1 = 0;
		if ((a[1] xor a[2]) == k) {
			ans1 = 1;
		}

		if (a[1] == k)
			ans++;
		if (a[2] == k)
			ans++;

		cout << max(ans1, ans);
		return 0;
	}
	if (k == 0) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0) {
				cnt++;
			}

		}
		cout << cnt;
		return 0;
	} else {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int j = 1; j <= n - i; j++) {
				s = (a[j] xor s);
			}
			if (s == k)
				cnt++;
		}
		cout << cnt;
	}
//	cout << (a[1] xor a[2]);
	return 0;
}
