#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	int k = a[1],hk = 0;
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i = 1;i <= n*m;i++)
	{
		if(a[i] == k)
		{
			hk = i;
		}
	}
	int hang = (hk+n-1)/n,lie = 0;
	if(hang % 2 == 1)
	{
		lie = (hk - (hang-1) * n);
	}
	else
	{
		lie = (hang * n - hk+1);
	}
	cout << hang << " " << lie;
	return 0;
}
