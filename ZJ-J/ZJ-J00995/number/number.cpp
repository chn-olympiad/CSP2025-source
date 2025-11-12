#include <bits/stdc++.h>
using namespace std;
char s[100010];
int len = 0, a[100010], f = 0;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	while (!(scanf("%c", &s[len]) == EOF)) len++;
	for (int i = 1; i <= len; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') continue;
		a[++f] = s[i] - '0';
	}
	for (int i = 1; i <= f; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j] < a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
	for (int i = 1; i <= f; i++) cout << a[i];
	return 0;
}