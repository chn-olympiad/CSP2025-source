#include<bits/stdc++.h>
using namespace std;

int n, m, a[105], R, ord, lie, hang;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == R) 
		{
			ord = n * m - i + 1;
			break;
		}
	}
	int res = 0;
	if(ord % n == 0)
	{
		lie = ord / n;
		res = n;
	}
	else
	{
		lie = ord / n + 1;
		res = ord - (lie - 1) * n;
	}
	
	if(lie % 2 == 1)
	{
		hang = res;
	}
	else
	{
		hang = n - res + 1;
	}
	cout << lie << " " << hang << endl;
	
	
	return 0;
} 

