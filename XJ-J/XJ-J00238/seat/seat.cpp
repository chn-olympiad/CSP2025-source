#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,n,m,b,s=1,d,e;
	cin>>n>>m;
	b=n*m;
	int a[b];
	for(i=1;i<=b;i++)
	{
		cin>>a[i];
	}
	for(i=2;i<=b;i++)
	{
		if(a[1]<a[i])
		{
			s++;
		}	
	 } 
	d=s/n+1;
	e=b-d*n;
	if(d%2==0)
	{
		e=n-e;
	}
	else
	{
		e=b-d*n;
	}
	cout<<d<<" "<<e;
	return 0;
}
