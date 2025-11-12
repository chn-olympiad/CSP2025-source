#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], id;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[id++] = s[i] - '0';
		}
	}
	sort(a, a + id, cmp);
	for (int i = 0; i < id; i++) {
		cout << a[i];
	}
	return 0;
}
