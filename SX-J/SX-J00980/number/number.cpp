#include <bits/stdc++.h>
using namespace std;
string s;
int sum, cnt, e, x;
char a[200];
int y = 57;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			cnt++;
			a[e] = s[i];
			e++;
		}
	}
	int g = cnt;
	for (int i = 0; i < 10; i++) {
		for (int q = 0; q < cnt; q++) {
			if (a[q] == y) {
				sum += (a[q] - '0') * pow(10, e - 1);
				e--;
			}
		}
		y--;
	}
	cout << sum;
	return 0;
}
