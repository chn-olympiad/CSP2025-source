#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
long long len, sum = 0, a[maxn];
char s[maxn];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	len = strlen(s + 1);
	for (int i = 1; i <= len; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[++sum] = s[i] - '0';
	sort(a + 1, a + 1 + sum);
	for (int i = sum; i >= 1; i--)
		cout << a[i];
	return 0;
}
