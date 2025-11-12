#include <bits/stdc++.h>
using namespace std;
string s;
int a[10000000];
int num = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - 48;
		} else {
			num++;
		}
	}
	sort(a, a + len - num, greater<int>());
	for (int i = 0; i < len - num; i++) {
		cout << a[i];
	}
	return 0;
}
