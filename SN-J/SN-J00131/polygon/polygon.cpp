#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(a[j]>a[j+1])
			{
				int p;
				p=a[j+1];
				a[j+1]=a[j];
				a[j]=p;
			}
		}
	}
	if(a[1]+a[2]>a[3]||a[3]-a[1]<a[2])
	{
		cout<<max(max(a[1],a[2]),a[3]);
	}
	else
	{
		cout<<0;
	}
	return 0;
}
