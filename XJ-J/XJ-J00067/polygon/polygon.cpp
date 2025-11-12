#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6 + 5;
long long int n, s[N], i, sum, mx;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (i = 1; i <= n; i ++) {
		cin >> s[i];
		sum += s[i];
		mx = max(mx, s[i]);
	}
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		if (mx * 2 < sum) {
			cout << mx;
			return 0;
		}
		else {
			cout << 0;
			return 0;
		}
	}
	cout << n + 1;
	return 0;
}
