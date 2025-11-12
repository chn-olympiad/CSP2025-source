#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen('seat.in','r',stdin);
	//freopen('seat.out','w',stdout);
	int n,m,a[105],x,t,w,d,e;
	cin >> n >> m;
	x=n*m;
    for (int i=0;i<x;i++)
    {
    	cin >> a[i];
	}
	w=a[0];
	for (int k=0;k<x;k++)
	{
	    for (int i=1;i<x;i++)
	    {
		    if (a[i]>a[i-1])
		    {
			    t=a[i-1];
			    a[i-1]=a[i];
			    a[i]=t;
		    }
	    }
    }
    for (int j=0;j<x;j++)
    {
    	if (a[j]==w)
    	{
    		d=j+1;
    		e=d/n;
    		if (d%n!=0)
    		    e+=1;
    		if (e%2==1)
    		    if (d%n==0)
    		        cout << e << ' ' << n;
				else
				    cout << e << ' ' << d%n;
    		else
				cout << e << ' ' << n-d%n;
		}
	}
	return 0;
}

