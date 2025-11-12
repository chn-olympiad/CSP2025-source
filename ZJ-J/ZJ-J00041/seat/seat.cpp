#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[150],g,p;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n*m;i++)
	{
		cin>>a[i];
	}
	g = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++)
	{
		if (a[i] == g)
		{
			p = i;
			break;
		}
	}
	//cout << p;
	int lie = (p-1)/n+1,hang;
	if (lie%2 == 1)
	{
		hang = p%n;
		if (hang == 0) hang+=n;
	}
	else 
	{
		hang = p%n;
		if (hang == 0) hang+=n;
		hang = n-hang+1;
	}
	cout << lie << " " << hang;
}
