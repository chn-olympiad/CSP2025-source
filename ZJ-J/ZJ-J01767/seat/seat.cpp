#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[105];
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m+1);
	int dj = lower_bound(a+1,a+n*m+1,r)-a;
	int zj = n*m-dj+1;
	int co = zj/n;
	int l = zj-(co-1)*n;
	while(l > n)
	{
		co++;
		l -= n;
	}
	if (co % 2 == 1)
	{
		cout << co << " " << l;
	}
	else
	{
		cout << co << " " << n-l+1;
	}
	return 0;
}
