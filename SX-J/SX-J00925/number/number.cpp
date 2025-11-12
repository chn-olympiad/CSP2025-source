#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int j = 1;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	feropen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for (int i = 0; i <= n; i++) {
		if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a + 1, a + j + 1, cmp);
	for (int i = 1; i < j; i++) {
		cout << a[i];
	}
	cout << endl;
	return 0;
}
