#include<bits/stdc++.h>
using namespace std;
int mian()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon .out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin>>x;
		if(n>x)
		{
			cout<<x*n;
		}
	}
	return 0;
}
