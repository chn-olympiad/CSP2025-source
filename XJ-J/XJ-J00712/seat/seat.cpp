#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,b[105][105],z;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	z=a[1];
	s=n*m;
	sort(a+1,a+s+1);
	for(int i=n*m;i>=1;i--)
	{
		if(z==a[i])
		{
			s=i;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(z-i*n>=0) 
		cout<<i<<" "<<s;
	}
	
	return 0;
}
