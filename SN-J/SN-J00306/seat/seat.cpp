#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,a[x],c,b,max,y=1,z=2;
	cin>>n>>m;
	x=n*m;
	cin>>a[x];
	for(int x=1;x<=n*m;x++)
	if(a[x]<a[x+1])
	{
	a[x]=c;
	a[x+1]=b;
	b=a[x];
	c=a[x+1];
	}
	a[1]=(y,z);
	cout<<a[1];
		return 0;
}
