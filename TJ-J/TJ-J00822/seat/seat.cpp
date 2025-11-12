#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1100];
int r, rw;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (r == a[i])
		{
			rw = i;
			break;
		}
	int lie = (rw - 1) / n + 1;
	int hang;
	if (lie % 2 == 0)
	{
		hang = n - (rw - ((lie - 1) * n)) + 1;
	} 
	else
	{
		hang = rw - ((lie - 1) * n);
	}
	cout << lie << " " << hang;
	return 0;
}
