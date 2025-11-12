#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,s;
int a[1000];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int f=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m*n;i++)
		if(f==a[i])
			s=n*m-i+1;
	if(s%n==0)
		c=s/n;
	else
		c=s/n+1;
	if(c%2==1)
	{
		r=s%n;
		if(r==0)
			r=n;
	}
	else
	{
		if(s%n==0)
			r=1;
		else	
			r=n-s%n+1;
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}