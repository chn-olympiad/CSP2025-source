#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int a[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int i = 0, n = 1;
	while (((int)(s[i] - '0') >= 0 && (int)('9' - s[i]) >= 0 ) || ((int)(s[i] - 'a') >= 0 && (int)('z' - s[i]) >= 0)) {
		if ((int)(s[i] - '0') >= 0 && (int)('9' - s[i]) >= 0) {
			a[n] = (int)(s[i] - '0' );
			n++;
		}
		i++;
	}
	sort(a + 1, a + n + 1);
	for (int j = n; j > 1; j--) {
		cout << a[j];
	}
	return 0;
}