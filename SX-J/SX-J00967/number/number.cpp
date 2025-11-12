#include <bits/stdc++.h>
using namespace std;
int n[1000005], l = 1, c;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n[l] = s[i] - '0';
			l++;
		}n
	}
	sort(n + 1, n + l);
	for (int i = l - 1; i >= 1; i--) {
		cout << n[i];
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
