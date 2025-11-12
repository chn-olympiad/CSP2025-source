#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			m++;
			a[m] = s[i] - '0';
		}
	}
	sort(a + 1, a + m + 1);
	for (int i = m; i >= 1; i--)
		cout << a[i];
	cout << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}