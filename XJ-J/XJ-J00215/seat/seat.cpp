#include<bits/stdc++.h>
using namespace std;
long long int a[105],i,m=0,j,c,r,n,s,l,b=1,d=1;
int main() 
{
		freopen("seat.in","r",stdin);
	    freopen("seat.out","w",stdout);
	    cin>>n>>m;
	    s=n*m;
	    for(i=1;i<=s;i++)
	    cin>>a[i];
	    l=a[1];
	    sort(a+1,a+1+s,greater<long long int>());
	    for(i=1;i<=s;i++) 
	    if(a[i]==l)
	    {
	    	l=i;
	    	break;
		}
		if(l%n==0)
		{
			b=l/n;
			if(b%2==0)
			cout<<b<<" "<<1;
			else
			cout<<b<<" "<<n;
		}
		else
		{
		l=i;
     while(l>n)
	{
	
			l=l-n;
			d++;
	}
	if(d%2==0)
	{
		if(l==1)
		cout<<d<<" "<<n;
	    else
	    cout<<d<<" "<<n-l;
}
else
	cout<<d<<" "<<l;

}
	    	return 0;
}
