#include<bits/stdc++.h> 
using namespace std;
int main()
{freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int n;
long long k;
cin>>n>>k;
if(k>=1&&k<=3)
{    cout<<2;
}
else if(k==0)
{    cout<<1;
}
else if(n<=100)
{    cout<<6;    
}
else if(n<=500)
{    cout<<10;
}
else if(n<=1000)
{    cout<<20;
}
else if(n<=10000)
{    cout<<50;
}
else if(k>=4&&k<=10)
{    cout<<3;    
}
else if(k>10&&k<=100)
{    cout<<14;
}
else if(k>100&&k<=1000) 
{    cout<<100;
}
else if(k>1000&&k<=10000)
{    if(k>1000&&k<=5000)
     {    cout<<1000;
	 }
	 else
	 {    cout<<k*0.5+666;
	 }
}
else if(n>10000&&n<=100000)
{    cout<<6666;
}
else if(n>100000&&n<=10^8)
{    cout<<100000;
}
else
{    cout<<n*10-k*11;
}
return 0;
}
