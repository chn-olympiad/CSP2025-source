#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r;
	int seat=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			seat++;
		}
	}
	c=seat/n;
	r=seat%n;
	if(seat%n==0)
	{
		cout<<c<<" "<<n;
	}
	else if((c+1)%2==0)
	{
		cout<<c+1<<" "<<n-r+1;
	}
	else
	{
		cout<<c+1<<" "<<r;
	}
	return 0;
}
