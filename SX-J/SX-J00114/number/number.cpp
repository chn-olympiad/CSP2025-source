#include <bits/stdc++.h>
using namespace std;
string s;
long long b[1000005];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long n = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b[n] = s[i] - '0';
			n++;
		}
	}
	sort(b + 0, b + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << b[i];
	}
	return 0;
}
