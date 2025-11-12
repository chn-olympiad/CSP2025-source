#include <bits/stdc++.h>
using namespace std;
string s;
char a[100005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int sum = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum++;
			a[sum] = s[i];
		}
	}
	int l2 = 0;
	for (int i = 0; a[i] >= '0'; i++)
		l2++;
	sort(a, a + l2 + 1);
	for (int i = l2; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
