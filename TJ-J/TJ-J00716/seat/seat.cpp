#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int n,m,c=0,r=0,sum,d=0;
	long long int a[105],b;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b=a[1];
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--)
	{
		d++;
		if(a[i]==b)
		{
			if(d%2==1)
			{
				c=d/m+1;
				sum=d/m+1;
			}
			else if(d%2==0)
			{
				c=d/m;
				sum=d/m;
			}
			if(sum%2==1)
			{
				r=d-(sum-1)*n;
			}
			else if(sum%2==0)
			{
				r=sum*n-d+1;
			}
		}
	} 
	cout<<c<<" "<<r<<endl;
	return 0;
}
