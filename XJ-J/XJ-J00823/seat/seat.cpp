#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100100],x,y;
	cin>>n>>m;
	cin>>x;
	a[1]=x;
	for(int i=2; i<=m*n; i++)
	{
		cin>>y;
		a[i]=y;
	}
	sort(a+1,a+n*m+1);
	int b;
	for(int i=1; i<=m*n; i++)
	{
		if(a[i]==x) b=m*n-i+1;
	} 
	int q,w;
	if(b<=n)
	{
		q=1;
		w=n;
	}
	else if(b%n==0)
	{
		if((b/n)%2==0)
		{
			q=b/n;
			w=1;
		}
		else
		{
			q=b/n;
			w=n;
		}
	}
	else
	{
		if((b/n+1)%2==0)
		{ 
			q=b/n+1;
			w=n-b%n+1;
		}
		else
		{
			q=b/n+1;
			w=b%n;
		}
	}
	cout<<q<<" "<<w;
	
	return 0;
}
