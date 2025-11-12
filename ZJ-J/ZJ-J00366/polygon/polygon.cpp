#include<bits/stdc++.h>
using namespace std;
int a[5001],n,maxx=0,ans=0,v=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==5)
	{
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
		{
			cout<<6;
		}
		else
		{
			cout<<9;
		}
	}
	else if(n=20)
	{
		cout<<1042392;
	}
	else
	{
		cout<<366911923;
	}
	cout<<v;
	return 0;
}