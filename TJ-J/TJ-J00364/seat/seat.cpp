#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,x,a=1,b=1,c,d;
	cin>>n>>m;
    for(int i=1;i<=n*m;i++)
	{ 
	    cin>>x;
		if(i==1)
		{
			a=x;
		}
		if(x>a)
		{
			b+=1;
		}
    }
    c=(b/(2*n)*2);
    if(b%(2*n)>n)
    {
	   c+=2;
	   d=n-(b%(2*n-n))+1; 
	}
	if(b%(2*n)==0)
	{
		c+=0;
		d=n;
	}
	if(b%(2*n)>=1&&b%(2*n)<(n+1)) 
	{
		c+=1;
	    d=b%(2*n);
	}
    cout<<c<<" "<<d;
	return 0;
 } 
