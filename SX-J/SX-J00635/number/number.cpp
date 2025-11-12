#include <bits/stdc++.h>
using namespace std;
char a[1000005];

int main() {
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)

	string s;
	cin >> s;
	long long b = s. size();
	for (long long i = 0; i <  b; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
		}
	}
	sort(a, a + b);
	for (long long i = b; i >= 0; i--) {
		if (a[i] != 0)
			cout << a[i];
	}
	return 0;
}
