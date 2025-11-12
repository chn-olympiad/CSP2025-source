#include <bits/stdc++.h>
using namespace std;
int a[1000005], l = 0, sum = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++l] = s[i] - '0';
	sort(a + 1, a + l + 1);
	for (int i = l; i >= 1; i--)
		sum = sum * 10 + a[i];
	cout << sum;
	return 0;
}
