#include<bits/stdc++.h>
using namespace std; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,a[100],e,f,b,g;
	cin>>c>>r>>e;
	for(int i=0;i<c*r-1;i++)
	{
		cin>>a[i];
        f=a[i];
		if(e<f)
		b++;
	}
	g=r;
	for(int d=0;d<c;d++)
	{
		if(b-g<=0)
		r=r*d+b-g, c=d;	
		else
		g=g+r;
		break;
	}
	cout<<c<<' '<<r; 
	return 0;
}
