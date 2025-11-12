#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int ss=a[1];
	sort(a+1,a+n*m+1);
	int j=n*m;
	for(int i=1;i<=n*m;i++)
	{
		b[j]=a[i];
		j--;
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==ss&&i%n!=0)
		{
			c=i/n+1;
			t=i%n;
			break;
		}
		else if(b[i]==ss&&i%n==0)
		{
			c=i/n;
			t=n;
			break;
		}
	}
	if(c%2!=0)
	{
		r=0+t;
	}
	else
	{
		r=n-t+1;
	}
	cout<<c<<" "<<r;
	return 0;
} 
