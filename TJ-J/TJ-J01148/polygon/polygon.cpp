#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5005];
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
	}
	int cnt = 0,x;
	int d = 0;
	for(int i = 1;i <= n ;i++)
	{
		cnt += a[i];
		if(a[i] > x)
		{
			x = a[i];
		}
		if(cnt > 2 * x)
		{
			d++;
		}
	}
	cout << d;
	return 0;
}
