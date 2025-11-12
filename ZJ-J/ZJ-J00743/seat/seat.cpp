#include <bits/stdc++.h>

using namespace std;

int a[110];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
		
	int x = a[1];
	
	sort(a + 1,a + 1 + n * m);
	
	int w = -1;
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == x)
		{
			w = n * m - i + 1;
			break;	
		}	
	}	
	
	int r = -1;
	int c = (w + n - 1) / n;
	
	if (c % 2 == 0)
		r = n - (w - (c - 1) * n) + 1;
	else
		r = w - (c - 1) * n;
		
	cout << c << " " << r;
	
	return 0;
}