#include <bits/stdc++.h>
using namespace std;
long long int n,m,l,p[105],a[105],k,z,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>p[i];
	}
	z=p[0];
	sort(p,p+n*m);
	for(int i=n*m-1;i>=0;i--)
	{
		a[k++]=p[i];
		if(p[i]==z)
		{
			l=k;
		}
	}
	y=l%(2*n); 
	x=l/(2*n);
	if(y<=n)
	{
		cout<<2*x+1<<" "<<y;
		return 0;
	}
	else
	{
		cout<<2*x+2<<" "<<2*n-y+1;
		return 0;
	}
	return 0;
}
