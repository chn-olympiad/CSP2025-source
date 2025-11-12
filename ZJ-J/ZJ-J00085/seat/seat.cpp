#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int rank, id;
}a[1005];

int n, m;

bool cmp(Node x, Node y)
{
	return x.rank > y.rank;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i].rank;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 0, y = 0, z = 0, p = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i].id == 1) {
			p = i;
			break;
		}
	}
	if (p % n == 0)
	{
		x = p / n;
		if (x % 2 != 0) y = n;
		if (x % 2 == 0) y = 1;
	}
	else
	{
		x = p / n + 1;
		z = p % n;
		if (x % 2 != 0) y = z;
		else y = n - z + 1;
	}
	cout << x << ' ' << y << '\n';
	return 0;
}
