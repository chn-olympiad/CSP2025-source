#include <bits/stdc++.h>
using namespace std;
int a[1000005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string ss;
	cin >> ss;
	int l = ss.size();
	if (l == 1 && ss[0] >= '0' && ss[0] <= '9') {
		cout << ss;
		return 0;
	}

	int cc = 0;
	for (int i = 0; i < l; i++) {
		if (ss[i] >= '0' && ss[i] <= '9') {
			cc++;
			a[cc] = ss[i] - '0';
		}
	}
	int ls = cc ;
	sort(a + 1, a + 1 + ls, cmp);
	for (int i = 1; i <= ls; i++) {
		cout << a[i];
	}
	return 0;
}