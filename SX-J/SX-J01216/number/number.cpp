#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
int num[MAXN];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int i;
	int n = s.size(), ans = -1;
	for (i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num[++ans] = s[i] - '0';
			//cout << ans;
		}
	}
	sort(num, num + n);
	//for (i = 0; i <= ans; i++) {
	//	cout << num[i];
//	}
	for (i = n - 1; i >= n - ans - 1; i--) {
		cout << num[i];
	}
	return 0;
}
