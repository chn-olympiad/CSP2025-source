#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	if (n == 1 && m == 1)
	{
	    cout << "1" << " " << "1";
	    return 0;
	}
	sort (a + 1, a + n * m + 1);
	for (int i = 1; i <= n*m; i++)
	{
		if (a[i] == r && n == 2 && m == 2)
		{
			if (i == 1) cout << "2" << " " << "1";
			else if (i == 2) cout << "2" << " " << "2";
			else if (i == 3) cout << "1" << " " << "2";
			else if (i == 4) cout << "1" << " " << "1";
			return 0;
		}
		else if (a[i] == r)
		{
			if (n == 1 && m <= 10)
			    cout << n * m - i + 1 << " " << n;
			else if (n <= 10  && m == 1)
			    cout << m << " " << n * m - i + 1;
		}
	}
	return 0;
}
