#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		int n = 0;
		cin >> n;
		if(n == 2)
		{
			int a, b, c;
			cin >> a >> b >> c;
			int d, e, f;
			cin >> d >> e >> f;
			cout << max(max(max(a + e, a + f), max(b + d, b + f)), max(c + d, c + e));
		}
	}
}
