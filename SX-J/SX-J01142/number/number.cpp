#include <bits/stdc++.h>
using namespace std;
long long a[1000005], l;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[l] = s[i] - '0';
			l++;
		}
	}
	sort(a, a + l, cmp);
	for (int i = 0; i < l; i++)
		cout << a[i];
	return 0;
}
