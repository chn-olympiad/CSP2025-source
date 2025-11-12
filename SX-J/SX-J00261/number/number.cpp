#include <bits/stdc++.h>
using namespace std;
vector<int> c;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			c.push_back(s[i] - '0');
	sort(c.begin(), c.end());
	len = c.size();
	for (int i = len - 1; i >= 0; i--)
		printf("%d", c[i]);
	puts("");
	return 0;
}
