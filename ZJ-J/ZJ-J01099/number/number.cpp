#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;

string str;
int a[MAXN];
int cnt = 0;

bool cmp (int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> str;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			a[++cnt] = str[i] - '0';
		}
	}
	
	sort (a + 1, a + 1 + cnt, cmp);
	
	for (int i = 1; i <= cnt; i++)
	{
		cout << a[i];
	}
	
	cout << "\n";
	
	return 0;
}

