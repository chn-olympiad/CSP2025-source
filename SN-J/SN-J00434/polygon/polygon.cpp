#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],sum = 0,num = 0;
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		sum+=a[i];
	}
	if(sum>a[n])
	{
		num++;
	}
	cout << num%998244353 << endl;
	return 0;
}
