#include<bits/stdc++.h>
using namespace std;
int n,m,g,p=1,a,b,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	g=n*m-1;
	cin>>a;
	for(int i=0;i<g;i++)
	{
		cin>>b;
		if(b>a)
		p++;
	}
	c=(p-1)/n+1;
	r=p-(c-1)*n;
	if(c%2==0)
	{
		r=n-r+1;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
