#include<bits/stdc++.h>
using namespace std;
int a[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k,n,m,s,t,x=0,y=0;
	int b[10005];
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	s=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(b[i]==s)
		{
			j=i;
			break;
		}
	} 
	if(j<=n)
	{
		x=1;
	}
	else
	{
		if(j%n==0)
		{
			x=j/n;	
		}
		else
		{
			x=j/n+1;
		}
	
	}
	if(x%2!=0)
	{
		if(j>n)
		{
			y=j%n;
		}
		else
		{
			y=j;
		 } 
		
	}
	else
	{
		if(j%n==0)
		{
			y=1;
			
		}
		else
		{	
			
			y=n-j%n+1;
		}
	
	}
	cout<<x<<" "<<y<<" ";
	return 0;
}
