#include <bits/stdc++.h>
using namespace std;
string s, p;
int  m;
char a[1000010];

bool l(int x, int y) {
	return x > y;

}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] == '1' || s[i] == '0' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
		        || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			m++;
			a[m - 1] = s[i];

		}
	}
	sort(a, a + m - 1, l);
	for (int i = 0; i < m; i++) {
		cout << a[i];
	}
	return 0;
}
