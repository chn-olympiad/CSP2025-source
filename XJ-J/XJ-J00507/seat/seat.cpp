#include<bits/stdc++.h>
using namespace std;
long long int m,n,a[10][10],b[10][10],c[105],i,j=1,d=1,g;
int main()
{
	freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
  cin>>n>>m;
    for(i=1;i<=n*m;i++)
    cin>>c[i];
    g=c[1];
    sort(c+1,c+n+1);
    i=n*m;
    while(i!=0)
   {
   	
   	  if(j%2==0)
   	  {
   	  d--; 
		 i--;
   	   if(c[i]==g)
   	   {cout<<d<<" "<<j;
		return 0;
		  }
   	  	
   }
   	  if(j%2==1)
   	  {
		}
   	  d++; 
		 i--;
   	   if(c[i]==g)
   	   {cout<<d<<" "<<j;
   	  	return 0;
   	  	
   }
   	  if(d==1||d==n)
   	  {  j++; if(c[i]==g)
   	    {cout<<d<<" "<<j;
   	  	return 0;
		   }
   	 
   	  
   	 
   	  	
   }
}
	return 0;
}
