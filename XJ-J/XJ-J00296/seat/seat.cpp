#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,a[120]={0},b,s=0,n2,m2;
	cin>>n>>m;
	t=n*m;
	for(int i=1;i<=t;i++)
	{
		cin>>b;
		if(i==1)
		{
			a[b]++;
		}
		a[b]++;
	}
	for(int i=100;i>=0;i--)
	{
		if(a[i]!=0)
		{
			if(a[i]==2)
			{
				s++;
				break;
			} 
			s++;
		} 
	}
	if(s%n==0)
	{
		m2=s/n;
		cout<<m2<<" "<<n;
		return 0;
	}
	else
	{
		m2=s/n+1;
	}
	if(m2%2==1)
	{
		n2=s%n;
	}
	else if(m2%2==0)
	{
		n2=n-s%n+1;
	}
	cout<<m2<<" "<<n2;
	return 0;
} 
