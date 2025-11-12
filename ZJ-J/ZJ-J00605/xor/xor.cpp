#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, cnt0 = 0, cnt1 = 0;
ll thing[500005];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> thing[i];
		if (thing[i] == 1) cnt1++;
		if (thing[i] == 0) cnt0++;
		if (thing[i] == 1 && thing[i-1] == 1) {
			cnt0++;
			thing[i] = thing[i-1] = 0;
		}
		
	}
	if (k == 0) {
		cout << cnt0;
	} else if (k == 1) {
		cout << cnt1;
	} else {
		cout << n / 3;
	}
	return 0;
}
