#include <bits/stdc++.h>
using namespace std;

struct node
{
	int cj,id;
}a[105];

bool cmp (node a, node b)
{
	return a.cj > b.cj;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i].cj;
		a[i].id = i;
	}
	sort (a+1, a+n*m+1, cmp);
	int r;
	for (int i = 1; i <= n*m; i++)
	{
		if (a[i].id == 1)
		{
			r = i;
			break;
		}
	}
	int l = (r-1)/n+1;
	int h = r-(l-1)*n;
	if (l % 2)
		cout << l << " " << h;
	else
		cout << l << " " << n-h+1;
	return 0;
}
