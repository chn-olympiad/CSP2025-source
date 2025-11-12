#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int s=1;
int b=1,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(x==a[i])
		{
			break;
		}
		s++; 
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=n;j++)
		    {
			    if(s==b)
			    {
				   cout<<i<<" "<<j;
			    }
			    	b++;	        
		    }
		}
		else
		{
			for(int j=n;j>=1;j--)
		    {
			    if(s==b)
			    {
			        cout<<i<<" "<<j;
			    }
		    	b++;
		    }
		}
		
	} 
	
	return 0;
}
