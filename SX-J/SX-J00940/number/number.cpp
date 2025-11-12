#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
char a[N];
int m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	if (n <= 1 && s[0] >= '0' && s[0] <= '9') {
		cout << s[0];
	} else {
		for (int i = 0; i < n; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				m++;
				a[m] = s[i];
			}
		}
		sort(a + 1, a + m + 1);
		for (int i = m; i >= 1 ; i--)
			cout << a[i];
	}
	return 0;
}
