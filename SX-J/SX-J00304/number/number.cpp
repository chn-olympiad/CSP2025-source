#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
priority_queue<ll> q;
char a[1000010];
ll sum = 1;

int qread() {
	char c = getchar();
	int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

void qwrite(int n) {
	if (n >= 10)
		qwrite(n / 10);
	putchar(n % 10 + '0');
}

int cmp(char aa, char bb) {
	return aa > bb;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[sum] = s[i];
			sum++;
		}
	}
	sort(a + 1, a + sum + 1, cmp);
	for (int i = 1; i <= sum; i++)
		cout << a[i] ;
	return 0;
}
