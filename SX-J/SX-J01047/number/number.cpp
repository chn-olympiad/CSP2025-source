#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int top, num[1000005];

int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin.getline(s + 1, 1000005);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) {
		if (s[i] <= '9' && s[i] >= '0')
			num[++top] = s[i] - '0';
	}
	sort(num + 1, num + top + 1);
	for (int i = top; i >= 1; i--)
		cout << num[i];
	return 0;
}
