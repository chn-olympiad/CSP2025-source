#include <bits/stdc++.h>
using namespace std;

int a[1000005] = {-1};
int x = 0, y = 0;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int b = s.size();
	for (int i = 0; i < b; i++) {
		if (s[i] == '0') {
			y++;
		}
		if (s[i] >= '1' && s[i] <= '9' ) {
			x++;
			a[x] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + x);
	for (int i = x; i >= 1; i--) {
		cout << a[i];
	}
	for (int i = 1; i <= y; i++) {
		cout << 0;
	}
	return 0;
}
