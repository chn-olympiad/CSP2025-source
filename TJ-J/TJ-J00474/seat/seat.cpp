#include <bits/stdc++.h> 
using namespace std;
int main()
{
	
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);

   int a[100001];
    int n,m;
    int c=0,r=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {     cin>>a[i];
    
    	if(r++&&a[a[i]i]]>a[a[i]-1])
      {
     continue;
	  }
	  else
	  {m--;
	  	c++; 
	  }
    if(a[a[i]-1]>a[a[i]])
      {
     continue;
	  }
	  else
	  {n--;
	  	r++; 
	  }	
	}
      
    	
	
      
		
     
	
      
	  cout<<c<<" "<<r;
	return 0;
}
