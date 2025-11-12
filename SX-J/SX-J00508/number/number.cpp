#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int a[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int lean = s.size();
	for (int i = 1; i <= lean; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
		}
	}
	for (int i = 1; i <= lean; i++) {
		a[i] = max(a[i], a[i + 1]);
		cout << a[i];
	}
	return 0;
}