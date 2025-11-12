#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n*m + 1];
    for(int i = 1; i <= n*m; i++)
    {
    	cin >> a[i];
	}
	int a1 = a[1];
	sort(a+1, a+n*m+1, cmp);
	int cnt = 0;
	for(int i = 1; i <= n*m; i++)
	{
		if(a1 == a[i])
		{
			cnt = i;
			break;
		}
	}
	int lie = 0;
	if (cnt % n == 0)
	{
		lie = cnt / n;
	}
	else
	{
		lie = cnt / n+1;
	}
	int hang = 0;
	if (lie % 2 == 1)
	{
		if (cnt % n == 0)
		{
			hang = n;
		}
		else
		{
			hang = cnt % n;
		}
	}
	else
	{
		hang = n = cnt % n +1;
	}
	cout << lie << " " << hang;
    return 0;
}

