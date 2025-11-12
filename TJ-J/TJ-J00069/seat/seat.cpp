#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a[105];
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{   cin>>a[i];	 
}
int b=a[1];
sort(a+1,a+n*m+1);
for(int i=n*m;i>=1;i--)
{    if(a[i]==b)
     {    if((n*m-i+1)%n==0)
          {    cout<<(n*m-i+1)/n<<" "<<n;
		       break;
		  }
		  else
		  {    cout<<(n*m-i+1)/n+1<<" "<<(n*m-i+1)%n;
		       break;
		  }
	 }
}
return 0; 
}
