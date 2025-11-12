#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string s;
	cin >> s;
	int b = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b++;
			a[b] = s[i] - '0';
		}
	}
	sort(a + 1, a + b + 1);
	for (int i = b; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
