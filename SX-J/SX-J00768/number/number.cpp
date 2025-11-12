#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int len = 0;
	char t[s.size()];
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			t[len++] = s[i];
	}
	sort(t, t + len );
	for (int i = len - 1; i >= 0; i--) {
		cout << t[i];
	}
	return 0;
}
