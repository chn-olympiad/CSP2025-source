#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], top, l = 1;

bool cmp(int a, int b) {
	return a >= b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++top] = s[i] - '0';
	sort(a + 1, a + top + 1, cmp);
	while (l < top && a[l] == 0)
		l++;
	for (int i = l; i <= top; i++)
		cout << a[i];
	return 0;
}
