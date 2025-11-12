#include<bits/stdc++.h>
using namespace std;
int a[3],b=0;
int main()
{
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	for(int i=0;i<3;i++)
	{
		cin>>a[i];
		b=max(a[i],b);
	}
	if(a[0]+a[1]>b&&a[1]+a[2]>b&&a[0]+a[2]>b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}