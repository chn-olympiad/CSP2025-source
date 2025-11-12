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
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int l=j;l<=n;l++)
			{
				if(a[i]+a[j]+a[l]>max(a[i],max(a[j],a[l]))*2)
				x++;
			} 
		}
	}
	cout<<x;
	return 0;
} 
