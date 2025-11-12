#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,c,num,x;
	double numdo;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>x;
		a[i]=100-x;
	}
	s=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==s)
		{
			num=i+1;
			numdo=num;
			break;
		}
	}
	c=ceil(numdo/n);
	cout<<c<<" ";
	if(c%2==1)
	{
		if(num%n==0)
		{
			cout<<n;
		}
		else
		{
			cout<<num%n;
		}
	}
	else
	{
		cout<<1-(num-c*n);
	}
	return 0;
 } 
