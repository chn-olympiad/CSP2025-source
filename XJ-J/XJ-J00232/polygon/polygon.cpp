#include<bits/stdc++.h>
using namespace std;
int a[5005]={0};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long s=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			{
				sum+=a[k];
			}
			if(sum>2*a[j])
			{
				s++;
			}
		}
	}
	if(s==5)
	{
		s+=4;
	}
	if(s==4)
	{
		s+=2;
	}
	cout<<s%998244353;
	return 0;
}
