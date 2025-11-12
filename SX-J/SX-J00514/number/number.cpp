#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;
int cnt = 0;

bool cmp(int x, int y) {
	if (x > y)
		return true;
	else
		return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	s = " " + s;
	int len = s.size();
	for (int i = 1; i < len; i++)
		if (s[i] == 48 || s[i] == 49 || s[i] == 50 || s[i] == 51 || s[i] == 52 || s[i] == 53 || s[i] == 54
		        || s[i] == 55 || s[i] == 56 || s[i] == 57) {
			a[i] = s[i];
			cnt++;
		}
	sort(a + 1, a + len + 1, cmp);
	for (int i = 1; i <= cnt; i++)
		cout << a[i] - 48;
	return 0;
}
