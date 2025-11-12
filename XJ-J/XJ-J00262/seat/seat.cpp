#include<bits/stdc++.h>
using namespace std;
long long int b[100000],a[100000],n,m,i,j,f,l,k,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	f=b[1];
	sort(b+1,b+1+n*m);
	for(i=n*m,j=1;i>=1,j<=n*m;i--,j++)
	{
		a[j]=b[i];
	}
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==f)
		{
			k=i;
		}
	}
	j=k%n;
	if(j!=0)
	{
		l=(k-j)/n+1;
		cout<<l<<" ";
	}
	else
	{
		l=k/n;
		cout<<l<<" ";
		j=n;
	}
	if(l%2!=0)
		{
			cout<<j;
		}
		else
		{
			for(i=n;i>=j;i--)
			{
				 x++;
			}
			cout<<x;
		}
	return 0;
} 
