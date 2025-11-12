#include <bits/stdc++.h>
using namespace std;

//const double MAX_TIME = ;

long long n, m, a[1005];

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	long long r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int i = 1, j = 1, k = 1, f = 1;
	for (; i <= n && j <= n; )
	{
//		cout << i << " " << j << " " << f << endl;
		if (a[k] == r)
		{
			cout << j << " " << i; 
			return 0;
		}
		if (i == n && f == 1) j++, f = -1;
		else if (i == 1 && f == -1) j++, f = 1;
		else i += f;
		k++;
	}
	return 0;
}
