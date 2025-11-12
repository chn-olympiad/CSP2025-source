#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[505];
int c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> a;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	if (m == n)
	{
		int num = 0;
		for (int i = 0; i < strlen(a); i++)
		{
			if(a[i] == 49)
			{
				num++;
			}	
		}
		if (num == strlen(a))
		{
			cout << 1;
		}
		else
			cout << 0;
	}
	return 0;
}
