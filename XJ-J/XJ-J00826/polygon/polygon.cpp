#include <iostream>
using namespace std;
int n,a[10000000],o[100],num,sum,k;
int main()
{
	//freopen("polygon","r",stdin);
	//freopen("polygon","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(a[i]>=a[i-1])
		{
			o[0]=a[i-1];
			a[i]=a[i-1];
			o[0]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	sum-=a[0];
	num=a[0];
	num*=2;
	for(int i=1;i<=n;i++)
	{
		if(sum>num)
		{
			k++;
		}
	}
	cout<<k;
}
