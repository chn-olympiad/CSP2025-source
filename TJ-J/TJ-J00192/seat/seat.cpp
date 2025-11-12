#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1005];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int sq = n * m;
	int sign;
	for(int i = 1; i <= sq; i++)
	{
		cin >> a[i];
	}
	sign = a[1];
	sort(a + 1, a + sq + 1);
	for(int i = 1; i <= sq; i++)
	{
		if(sign == a[i])
		{
			sign = i;
			break;
		}
	}
	sign = sq - sign + 1;
	int c = sign / (2 * n), d = sign % (2 * n);
	c = 2 * c + 1;
	if(d > n)
	{
		d = 2 * n - d + 1;
		c++;
	}
	cout << c << " " << d;
	return 0;
}
