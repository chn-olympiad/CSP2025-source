#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	int n,i,a[50005];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
		{
			cout<<"1";
			break;
		}
		else
		{
			cout<<"0";
			break;
		}
	}
	return 0;
}
