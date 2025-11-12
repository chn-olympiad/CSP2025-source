#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dou double
#define str string

//AC_tgoyyx

const ll N = 1e6;
str s;
int n[N], sum = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	getline(cin, s);
	s = ' ' + s;

	for (int i = 1; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum++;
			n[sum] = s[i] - '0';
		}
	}

	sort(n + 1, n + sum + 1, cmp);

	for (int i = 1; i <= sum; i++) {
		cout << n[i];
	}

	return 0;
}
