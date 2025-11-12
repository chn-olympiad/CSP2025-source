#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	int j = 1;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a + 1, a + j, cmp);
	for (int i = 1; i <= j - 1; i++) {
		cout << a[i];
	}
	return 0;
}
