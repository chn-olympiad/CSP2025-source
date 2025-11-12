#include <bits/stdc++.h>
using namespace std;
string s;
const long long N = 1e6+5;
int a[N];
int j;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a, a + j);
	for (int i = j - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}