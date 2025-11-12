#include <bits/stdc++.h>
using namespace std;
int s[1000005];

bool cmp(int a, int b) {
	return a > b;
};

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int c = a.size(), cnt = 0;

	for (int i = 0; i < c; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			cnt++;
			s[cnt - 1] = a[i] - '0';

		}
	}
	sort(s, s + cnt, cmp);

	for (int i = 0; i < cnt; i++) {
		cout << s[i];
	}

	return 0;
}
