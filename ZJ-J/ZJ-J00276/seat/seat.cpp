#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], t, s;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%d", &t);
	a[1] = t;
	for(int i = 2; i <= n * m; i++)
	{
		scanf("%d", a + i);
	}
	sort(a + 1, a + 1 + n * m);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == t)
		{
			s = i;
		}
	}
	s = n * m - s + 1;
	int i = 1, j = 1;
	s--;
	for(; s; s--)
	{
		if(j & 1)
		{
			if(i == n)
			{
				j++;
			}
			else i++;
		}
		else
		{
			if(i == 1)
			{
				j++;
			}
			else i--;
		}
	}
	cout << j << " " << i;
}
