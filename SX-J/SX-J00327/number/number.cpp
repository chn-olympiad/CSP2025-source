#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string st;
int cnt = 0, a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		if (st[i] - '0' >= 0 and st[i] - '0' <= 9) {
			a[i + 1] = st[i] - '0';
			cnt++;
		}
	}
	sort(a + 1, a + 1 + st.size(), cmp);
	for (int i = 1; i <= cnt; i++) {
		cout << a[i];
	}
	return 0;
}