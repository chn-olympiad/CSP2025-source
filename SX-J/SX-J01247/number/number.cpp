#include <bits/stdc++.h>
using namespace std;
long long a[1000000000000000001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long l = s.size();
	int sum = 1;
	for (long long i = 0; i < l; i++) {
		if ((s[i] - '0') >= 0 && (s[i] - '0') <= 9) {
			a[sum] = s[i] - '0';
			sum++;
		}
	}
	sort(a + 1, a + sum);
	long long ans = 0, t = 1;
	for (long long i = 1; i < sum; i++) {
		ans += a[i] * t;
		t = t * 10;
	}
	cout << ans << endl;
	return 0;
}
