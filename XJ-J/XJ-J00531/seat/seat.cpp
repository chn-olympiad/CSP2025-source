#include<bits/stdc++.h>
using namespace std;
int a[105],m,n,m2,t,c,j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+m*n+1);
	for(int i=m*n;i>=1;i--)
	{
		if(a[i]==t)
		{
			j=m*n-i+1;
			break;
		}
	}
	m2=(j-1)/n+1;
	if(m2%2==0)
	{
		c=n-(j-n*(m2-1))+1;
	}
	else
	{
		c=j-n*(m2-1);
	}
	cout<<m2<<" "<<c;
	return 0;
}
