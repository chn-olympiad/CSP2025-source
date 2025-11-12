#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size(), sum = 0, b, maxx, mh, sam = 0;
	int a[n + 3] = {0};
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b = char(s[i]) - 48;
			a[i] = b;
			sam++;
		}
	}
	for (int i = 0; i < sam; i++) {
		maxx = a[i];
		for (int k = 0; k <= sam - 1; k++) {
			if (max(a[k], a[k + 1]) == a[k + 1])
				maxx = a[k + 1];
		}
		mh = maxx;
		if (sam > 1) {
			for (int j = 0; j < sam - 1; j++) {
				mh = mh * 10;
			}
			sum = sum + mh;
		} else
			sum = sum + mh;
		a[i] = 0;
		sam --;
	}
	cout << sum ;
	return 0;
}
