#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

long long c = 0, a[5000000] = {0};
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < s.size() ; i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4'
		        || s[i] == '5' || s[i]  == '6' || s[i]  == '7' || s[i]  == '8' || s[i]  == '9'  ) {
			a[c] = s[i] - '0';
			c++;
		} else {
			n--;
		}
	}
	sort(a, a + c, cmp);
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}

	return 0;
}
