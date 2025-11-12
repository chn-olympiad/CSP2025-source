#include <bits/stdc++.h>
using namespace std;
int ss[10000005], nm;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;

	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8'
		        || s[i] == '9' || s[i] == '0' ) {
			ss[i + 1] = s[i] - '0';
			nm++;
		}

	}
	sort(ss + 1, ss + s.size() + 1, greater<int>());
	for (int i = 1; i <= nm; i++)
		cout << ss[i];
	return 0;
}