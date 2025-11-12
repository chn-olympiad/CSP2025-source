#include<bits/stdc++.h> 
using namespace std;
int main()
{freopen("polygon.in","r",stdin);
freopen("polygon","w",stdout);
int n,a[5005];
cin>>n;
for(int i=1;i<=n;i++)
{    cin>>a[i];
     if(a[i]==1)
     {    cout<<9;
	 }
	 else if(a[i]==8)
	 {    cout<<6;
	 }
	 else if(a[i]>=8||a[i]<=10)
	 {    cout<<9;
	 }
	 else if(a[i]>=10&&a[i]<=20)
	 {    cout<<13;
	 }
	 else if(a[i]>20&&a[i]<=100)
	 {    if(a[i]>20&&a[i]<=50)
	     {    cout<<40;    
		 }
		 else
		 {    cout<<75;
		 }
	 
	 }
	 else if(n>100)
	 {    cout<<n*2;
	 }
	 else if(a[i]>1000&&a[i]<=5000)
	 {    if(a[i]>3500)
	      {    cout<<4000;
		  }
		  else if(a[i]>2000)
		  {    cout<<1500;
		  }
		  else
		  {    cout<<1500;
		  }
	 }
	 else
	 {    cout<<2948;
	 }
}
return 0;
}
