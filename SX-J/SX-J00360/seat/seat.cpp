#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n,c,r,h;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++)
    {
	  cin>>a[i];
	}
    int k=a[1];
   for(int i=1;i<=m*n;i++)
	{
		for(int j=1;j<m*n;j++)
		{
			if(a[j]<a[j+1])
			{
				int x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}
	for(int i=1;i<=m*n;i++)
	{
		if(k==a[i]) h=i;
	}
     if(h%n==0)
	 {
	   c=h/n;
	   r=n;
     }
    else
	{
	   c=h/n+1;
       if(c%2==0) r=n-h%n+1;
         else r=h%n;
	}
    cout<<c<<" "<<r;
	return 0;
}