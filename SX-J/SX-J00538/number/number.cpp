#include <bits/stdc++.h>
using namespace std;
char a[10000000];

bool cmp(char x, char y) {
	return x > y ;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int  n = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
			n++;
		}

	}
	sort(a + 1, a + n + 3, cmp);
	for (int i = 0; i <= n ; i++)
		cout << a[i];
	return 0;
}
