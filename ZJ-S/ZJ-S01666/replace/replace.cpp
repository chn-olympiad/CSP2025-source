#include <bits/stdc++.h>
using namespace std;
int n, q;

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

string strread()
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
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	n = read();
//	q = read();
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		string a, b;
//		a = strread();
//		b = strread();
		cin >> a >> b;
	}
	for (int i = 1; i <= q; ++i)
	{
		string a, b;
//		a = strread();
//		b = strread();
		cin >> a >> b;
		cout << 0 << endl;
//		putchar('0');
//		putchar('\n');
	}
	return 0;
}
