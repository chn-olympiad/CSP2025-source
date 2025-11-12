#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

long long a[N] = {0}, id = 0;
string s;

bool cmp(long long c, long long b) {
	return c > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long len = s.size();
	for (long long i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			id++;
			a[id] = s[i] - '0';
		}
	}
	sort(a + 1, a + id + 1);
	for (int i = id; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
