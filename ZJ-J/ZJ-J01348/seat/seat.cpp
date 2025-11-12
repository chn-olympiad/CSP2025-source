#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N=100+33;
struct node
{
	int st, is;
}ar[N];
int cmp(node x, node y)
{
	return x.st>y.st;
}
int main()
{
	ios::sync_with_stdio(false);
	cin. tie (0), cout. tie (0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n*m; i++)
		cin>>ar[i].st;
	ar[1].is=1;
	sort (ar+1, ar+n*m+1, cmp);
	int x=1;
	for (int i=1; i<=m;)
	{
		for (int j=1; j<=n; j++)
		{
			if (ar[x].is==1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			x++;
		}
		i++;
		for (int j=n; j>=1; j--)
		{
			if (ar[x].is==1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			x++;
		}
		i++;
	}
	return 0;
}
