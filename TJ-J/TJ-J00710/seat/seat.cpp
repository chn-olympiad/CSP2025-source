#include<bits/stdc++.h>
using namespace std;
int n,m,sum,x,r,a[105];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{   
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n * m;
	for (int i = 1;i <= sum;i++)
	{
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1,a + sum + 1,cmp);
	for (int i = 1;i <= sum;i++)
		if (a[i] == x)
		{
			r = i;
			if (r % m == 0) cout << r / m << " ";
			else cout << r / m + 1 << " ";
			if (r % (2 * n) <= n) cout << r % (2 * n);
			else cout << n - (r % (2 * n) - n) + 1;
			return 0;
		}
	return 0;
}
