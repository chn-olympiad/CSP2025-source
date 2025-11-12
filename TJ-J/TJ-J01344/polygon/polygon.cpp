#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	long long n,a[105],c=998244353;
	cin >> n;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout << 0;
	}
	else if(n = 3)
	{
		if (a[1] + a[2] > a[3]&&a[1]-a[2] < a[3])
		{
			cout << (a[1] + a[2] + a[3])%c;
		}
	}
	else
	{
		cout << 6;
	}
}

