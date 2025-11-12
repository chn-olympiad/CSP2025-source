#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1],p;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{
			p=n*m-i+1;
			break;
		}
	}
	int ansn,ansm;
	cout<<p;
	ansm=ceil(1.0*p/n);
	if(ansm%2==0)
	{
		if(p%n==0)
		{
			ansn=1;
		}
		else
		{
			ansn=n-p%n+1;
		}
	}
	if(ansm%2==1)
	{
		ansn=p%n;
		if(ansn==0)
		{
			ansn=n;
		}
	}
	cout<<ansm<<" "<<ansn;
	return 0;
}