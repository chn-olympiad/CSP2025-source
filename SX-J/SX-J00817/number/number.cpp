#include <bits/stdc++.h>
using namespace std;
int a[10000005], j = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= j - 1; i++) {
		cout << a[i];
	}
	return 0;
}