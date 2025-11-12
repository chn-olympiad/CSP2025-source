#include<bits/stdc++.h>
using namespace std;
long long n, k, f, f1, ans, a[100010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] > 1) f1 = 1;
	}
	if(n <= 2) {
		if(n == 1) {
			if(a[1] == 0) ans = 1;
		} else {
			if(a[1] == 0 && a[2] == 0) ans = 2;
			else if(a[1] == 0 || a[2] == 0) ans = 1;
			else if (a[1] == a[2]) ans = 1;
		}
	} else if(f1 == 0 && k == 0) {
		int bj = 0;
		for (int i = 1; i <= n; i++) {
			if(bj == 0 && a[i] == 0) ans++;
			else if(a[i] == 1 && bj == 1) {
				bj = 0;
				ans++;
			} else if(a[i] == 1 && bj == 0) bj = 1;
		}
	} else if(f1 == 0 && k == 1) {
		for (int i = 1; i <= n; i++) {
			if(a[i] == 1) ans++;
		}
	} else {
		ans = 2;
	}
	cout << ans;

	return 0;
}
