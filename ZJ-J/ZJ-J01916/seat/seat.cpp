#include<bits/stdc++.h>
using namespace std;

int R, n, m, a[105];

bool cmp(int a, int b)
{
	return a > b;
}

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
	sort(a + 1, a + n * m + 1, cmp);
	int i = 1, x = 1, y = 1;
	bool up = false;
	while(i <= n * m)
	{
		if(a[i] == R)
		{
			cout << y << ' ' << x << endl;
			return 0;
		}
		if(up == false && x == n)
		{
			y++;
			up = true;
		}
		else if(up == true && x == 1)
		{
			y++;
			up = false;
		}
		else if(up)
		{
			x--;
		}
		else
		{
			x++;
		}
		i++;
	}
	return 0;
}