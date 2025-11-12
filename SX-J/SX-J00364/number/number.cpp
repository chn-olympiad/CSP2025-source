#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
string s;
int sum = 1, ans, len, a[N], j = 1, maxx = -1, l = 1, k;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size() - 1;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = (s[i] - 48);
			j++;
		}
	}
	if (j == 2) {
		cout << a[1];
		return 0;
	}
	sort(a + 1, a + j);
	for (int i = 1; i <= j - 1; i++) {
		ans += a[i] * sum;
		sum *= 10;
	}
	cout << ans;
	return 0;
}
