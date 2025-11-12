#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","f",stdin);
	freopen("culb.out","w",stdout);
	int t,n,a[10000],z,sum,x;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n;
		sum=0;
		for (int j = 1;j <= n;j++)
		{
			cin >> a[i];
			z += a[i];
			if (z%3==0 || z%2 == 0)
			{
				sum+=1
			}
		}
        if (sum>=1)
        {
        	for (int j = 1;j <= n;j++)
        	{
        		x+=a[i];
			}
			cout << x;
		}
	}
	return 0;
}
