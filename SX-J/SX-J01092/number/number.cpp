#include <bits/stdc++.h>
using namespace std;
long long b[1000001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 1;
	long long shu = s.size();
	for (int i = 0; i <= shu; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b[j] = s[i] - 48;
			j++;
		}
	}
	sort(b + 1, b + j + 1);
	for (int i = j; i >= 2; i--) {
		cout << b[i];
	}
}
