/*张潇扬  SN-J00386  西安市曲江第一中学*/ 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,a[999],R,c,r;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]<a[i+1])
		{
			int p=a[i];
			a[i]=a[i+1];
			a[i+1]=p;
		}
	}
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==R)
		{
			if(i%n==0)
			{
				c=i/n;
			 }	
			else
			{
				c=i/n+1;
			}
			if(c%2==0)
			{
				r=c*n+1-i;
			}
			else
			{
				r=i-(c-1)*n;
			}
		}
	 } 
	 cout<<c<<" "<<r;
	return 0; 
 } 
