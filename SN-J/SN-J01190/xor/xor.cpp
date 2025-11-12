#include <bits/stdc++.h>
using namespace std;
int n,a[10005],maxx;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxx)
		{
			maxx=a[i];
		}
	}
	cout<<maxx;
	return 0;
}

