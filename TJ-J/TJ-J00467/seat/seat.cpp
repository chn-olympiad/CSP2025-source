#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,h,l;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	for(long j=n*m;j>1;j--)
	{
		for(long c=1;c<j;c++)
		{
			if(a[c]>a[c-1])
			{
				int t=a[c-1];
				a[c-1]=a[c];
				a[c]=t;
			}
		}
	}

	for(int i=0;i<n*m;i++)
	{
		if(a[i]==r)
		{
			int j=i+1;
			l=j/m;
			if(l%2==0)
			{
				if(j%m>0)
				{
					cout<<l+1<<' '<<j%m; 
				 } 
				else
				{
					cout<<l<<' '<<1;
				}
			}
			else
			{
				if(j%n>0)
				{
					cout<<l+1<<' '<<n-j%m+1; 
				 } 
				else
				{
					cout<<l<<' '<<n;
				}
			}
		} 
	}
}
