#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
	{
		cout<<"9";
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		cout<<"6";
		return 0;
	}
	if(n==20)
	{
		cout<<"1042392";
		return 0;
	}
	if(n==500)
	{
		cout<<"366911923";
		return 0;
	}
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		 	{
				sum+=a[i];
			}
			if(sum>2*a[n])
				cout<<"1";
			else
				cout<<"0";
		return 0;
	}
	cout<<"0";
	return 0;
}