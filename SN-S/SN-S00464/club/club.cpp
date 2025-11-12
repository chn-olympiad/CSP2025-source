#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int k = 0;k < t;k++)
	{
		cin >> n;
		int a[100005],b,c,sum = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b >> c; 
		}
		sort(a+1,a+n+1);
		b = n/2;
		for (int i = n;i >= n-b+1;i--)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
	return 0;
}
