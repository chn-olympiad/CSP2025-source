//SN-J00493 朱皓天 渭南初级中学
#include <bits/stdc++.h> 
using namespace std;
int n, k, a[110];
int main()
{
	freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    cin >> n >>k;
    long long ans=0;
    	for (int i=0;i<=n;i++)
    	{
    		cin>>a[i];
    	}
		int x=1,y=-1;
	for (int i=1;i<=n,i++)
	{
	long long c=a[i];
		for (int j=0;j<=n;j++)
		{
			c*=a[j]
			if(c==k&&i>y)
			{
				x=i;
				y=j;
				ans++;
				cout << c;
			}
		}
	}
	cout <<ans;
    return 0;
}
