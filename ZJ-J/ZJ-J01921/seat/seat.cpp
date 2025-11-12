#include<bits/stdc++.h>
using namespace std;
int n, m, a[102];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int v = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int p;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == v)
		{
			p = i;
			break;
		}
	}
	int r = ceil(1.0 * p / n);
	int c = (p - 1) % n + 1;
	if(r % 2 == 0) c = n - c + 1;
	cout << r << ' ' << c;
	return 0;
}