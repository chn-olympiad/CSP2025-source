#include <bits/stdc++.h>

using namespace std;
int  n,m;

int main()
{
	freopen ("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
    cin>>n>>m;
    if(m==0)
    {
    	m=1;
	}
	
    int a[n*m+1]={ };
    for(int i=1;i<= n*m;i++)
    {
    	cin>>a[i];
	}
   int r=a[1];
 
	
    for(int j=1;j<=1000;j++)
   {
   	  for(int i=1;i<= n*m;i++)
   	  {
   		if(a[i+1]> a[i])
   		{
   			int x=a[i];
   			a[i]=a[i+1];
   			a[i+1]=x;
   		}
      }
    }
   	
   
   int cm;
 

   for(int i=1;i<=m*n;i++)
   {
   	if(a[i+1]==r)
   	{
   		cm=i+1; 
	   }
   }
 
   int x=cm/n;
   if(cm%n!=0)
   {
   	x+=1;
   }
   if(x<=0)
   {
   	 x=1; 
   }
   
   int y=cm%n;
   if( y <= 0)
   {
   	y=n; 
   }
   if(x%2==0)
   {
   	y=n-y+1;
   }
   cout<<x<<" "<<y;
   
	return 0;
 } 
