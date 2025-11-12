#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
string s;
int a[5005];
long long ans = 1;

int read()
{
	int num = 0;
	while (1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ')
		{
			return num;
		}
		num = num * 10 + int(c - '0');
	}
}

string readstr()
{
	string s = "";
	while (1)
	{
		char c = getchar();
		if (c == '\n' || c == ' ')
		{
			return s;
		}
		s = s + c;
	}
}

void write(int n)
{
	char c[11] = {};
	int len = 0;
	while (n)
	{
		c[++len] = char(n % 10 + '0');
		n /= 10;
	}
	for (int i = len; i >= 1; --i)
	{
		putchar(c[i]);
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	n = read();
//	m = read();
//	s = readstr();
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i)
	{
//		a[i] = read();
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		ans = ans * i;
		ans = ans % mod;
	}
//	write(ans);
	cout << ans;
	return 0;
}
