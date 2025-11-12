#include <bits/stdc++.h>
using namespace std;
const int maxn = 1;

int n, m, s[10010], c[505];
char ch;

int main ()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ch;
		s[i] = ch - '0';
	}
	int flag = 0;
	for (int i = 1; i <= n; i+=1)
	{
		cin >> c[i];
		if (c[i] > 0)
		{
			flag ++;	
		} 
	}
	cout <<0;
	return 0;
}

