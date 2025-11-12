#include <bits/stdc++.h>
using namespace std;
long long c[1000010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	long long len = s.size();
	long long num = 0;
	for (long long i = 0; i < len ; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			num++;
			c[num] = s[i] - 48;
		}
	}

	sort(c + 1, c + num + 1, cmp);

	for (long long i = 1; i <= num; i++) {
		cout << c[i];
	}
	return 0;
}
