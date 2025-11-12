#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], q;
char s = 's';
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	q = a[1];
	sort(a + 1, a + n * m + 1);
	int i = 1, j = 1, sum = 0;
	while(1)
	{
		sum++;
		if(a[n * m - sum + 1] == q)
		{
			cout << i << " " << j;
			return 0;
		}
		if(s == 's' && j + 1 > n)
		{
			i++;
			s = 'w';
		}
		else if(s == 'w' && j - 1 == 0)
		{
			i++;
			s = 's';
		}
		else if(s == 's')
		{
			j++;
		}
		else if(s == 'w')
		{
			j--;
		}
	}
	return 0;
}