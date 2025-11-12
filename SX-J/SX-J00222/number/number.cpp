#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int l,  cnt = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for (int i = 0; i <= l; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			continue;
		else {
			a[cnt] = s[i];
			cnt++;
		}
	}
	sort(a + 1, a + cnt + 1);
	for (int i = cnt ; i >= 1; i--)
		cout << a[i];
	cout << endl;
	return 0;
}