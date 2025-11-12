#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string h[N];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cnt = 0, n = s.size(), ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		a = s[i];
		if (a >= 48 && a <= 57) {
			ans++;
			h[ans] = s[i];
			cnt++;
		}
	}
	sort( h + 1, h + 1 + n);
	for (int i = n; i >= 0; i--) {

		cout << h[i];
	}

	return 0;
}
