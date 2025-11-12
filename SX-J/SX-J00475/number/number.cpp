#include <bits/stdc++.h>
using namespace std;
int a[1000000], as = 0;
string s;

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[as] = s[i] - '0';
			as++;
		}
	}
	sort(a, a + as);
	while (as--) {
		cout << a[as];
	}

	return 0;
}
//12343545454
//55544443321


