#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[105];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	int Mypoint = a[1];
	sort(a + 1, a + n * m + 1, greater < int > ());
	int cnt = 1;
	int i = 1, j = 1;
	bool vis = 0;
	while (cnt <= n * m)
	{
		if (Mypoint == a[cnt])
		{
			cout << j << " " << i << "\n";
			break;
		}
		if (vis == 0)
		{
			i++;
			if (i == n + 1)
			{
				vis = 1;
				j++;
				i--;
			}
		}
		else 
		{
			i--;
			if (i == 0)
			{
				vis = 0;
				j++;
				i++;
			}
		}
		cnt++;
	}
	return 0;
}

