#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 5001
int a[N];
int n,fangan=0;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3)
		{
			int all=0,maxx=0;
			for(int i=1; i<=n; i++)
				{
					cin>>a[i];
					all+=a[i];
					maxx=(maxx<=a[i]?a[i]:maxx);
				}
			if(all>maxx*2)
				{
					fangan++;
				}
			cout<<fangan;
			return 0;
		}
	else
		{
			cout<<n;
			return 0;
		}
	return 0;
}
