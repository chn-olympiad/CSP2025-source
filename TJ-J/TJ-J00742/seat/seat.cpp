#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[101];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int r=a[1];
	int num=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>r)
		{
			num++;
		} 
	}
	int h=num/n+1;
	int l=num-(h-1)*n;
	if(h%2==0 && n%2!=0)
	{
		if(l<n/2+1)
		{
			l=(n/2+1-l)+n/2+1;
		}
		else if(l>n/2+1)
		{
			l=n/2+1-(l-(n/2+1));
		}
	}
	else if(h%2==0 && n%2==0)
	{
		if(l==n/2)
		{
			l=l+1;
		}
		else if(l<n/2)
		{
			l=(n/2-1)+n/2+1;
		}
		else if(l>n/2)
		{
			l=n/2-(l-n/2)+1;
		}
	}
	cout<<h<<" "<<l;
	return 0;
}
