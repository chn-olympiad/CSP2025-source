#include<bits/stdc++.h>
using namespace std;
int a[5010];
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
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]>a[k])
				{
					cnt++;
				}
			}
		}
	}
	for(int h=4;h<=n;h++)
	{
		int sum=0;
		for(int j=1;j<h;j++)
		{
			sum+=a[j];
		}
		if(sum>a[h])
		{
			cnt++;
		}
	}
	cout <<cnt;
	return 0;
}
