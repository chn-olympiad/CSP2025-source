#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a[s.size()];
	long long qqq = 0;
	for (long long i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[qqq] = s[i] - '0';
			qqq++;
		}
	}
	sort(a, a + qqq);
	long long ppp;
	for (long long i = qqq - 1; i >= 0; i--) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
