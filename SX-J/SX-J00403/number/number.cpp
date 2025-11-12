#include <bits/stdc++.h>
using namespace std;
string s;
int n[1000005], a = 0, sum = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
		        || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			n[a] += s[i] - 48;
			a += 1;
		}
	}
	sort(n, n + a, cmp);
	for (int i = 0; i < a; i++) {
		sum += n[i] * pow(10, a - i - 1);
	}
	cout << sum;

	return 0;
}
