#include<bits/stdc++.h>
using namespace std;
long long int a[1000500],b[1000050],n,k=3,s,x,sum=0;
int fun(long long int r,long long int l)
{
	long long int i,j,m,q,t;
	for(i=r;i<=r+l-1;i++)
	{
		t+=a[i];
	}	if(t>2*a[i+l-1])
		return 1;
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		for(k=3;k<=n;k++)
		{
			s=k;
			if(i+k<=n)
			if(fun(i,k)==1)
			sum++;
		}
		
	}
	cout<<sum;
	return 0;
}  
