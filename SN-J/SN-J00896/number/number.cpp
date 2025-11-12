#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000003], in;
bool cmp (int x, int y) {
	return x > y;
}
int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[in] = s[i] - '0';
			in++; 
		}
	}
	sort (a, a + in, cmp);
	for (int i = 0; i < in; i++) {
		cout << a[i];
	}
	return 0;
} 
