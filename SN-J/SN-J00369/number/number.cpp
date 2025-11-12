//SN-J00369 张正轩 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = (s[i] - '0');
		}
	}
	sort(a + 1, a + 1 + cnt);
	for (int i = cnt; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
