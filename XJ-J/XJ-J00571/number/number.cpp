#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,k,n,t=0,sum=0;
	cin>>n;
	for(i=1;i<=1000005;i++)
	{
		a[i]=n%10;
		n=n/10;
		sum++;
		if(n==0)
		{
			break;
		}
	}
	for(i=1;i<=sum;i++)
	{
		for(j=i;j<=sum;j++)
		{
			if(a[i]<a[j])
			{
				t=a[i];
			    a[i]=a[j];
			    a[j]=t;
			}
			
		}
	}
	for(i=1;i<=sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
