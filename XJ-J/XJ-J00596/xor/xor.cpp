#include<bits/stdc++.h>
using namespace std;
int main()
{
//freopen(".in","r",stdin)
//freopen(".out","w",stdin)
int n,cd[100],m=0,flag=0,h,zd=0;
cin>>n;
for(int i=1;i<=n;i++){
    cin>>cd[i];
    h=cd[i]+cd[i+1];
	    if(zd<cd[i])
	    {
	    zd=cd[i];	
		}
	}
for(int i=1;i<=n;i++){
     if(n>3&&cd[i]==15&&zd==5)
     {
     	m++;
     	flag++;
	 }
	}
	if(flag>0)
	{
	cout<<m;	
	}		
return 0;		
}
