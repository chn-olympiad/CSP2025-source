#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005], len;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (isdigit(s[i]))
			a[++len] = s[i] - '0';
	sort(a + 1, a + len + 1, greater<int>());
	for (int i = 1; i <= len; i++) printf("%d", a[i]);
	return 0;
}

