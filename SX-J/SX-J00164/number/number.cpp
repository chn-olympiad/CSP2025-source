#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[10000000];

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	long long cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt++;
			a[cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		cout << a[i];
	}
}