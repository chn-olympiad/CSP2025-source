#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string a;
int as[N];
long long l = 0, d = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	l = a.size();
	for (int i = 0; i < l; i++) {

		if (a[i] >= '0' && a[i] <= '9') {
			d++;
			as[d] = a[i] - '0';
		}
	}
	sort(as + 1, as + d + 1);
	for (int i = d; i > 0; i--) {
		cout << as[i];
	}

	return 0;
}
