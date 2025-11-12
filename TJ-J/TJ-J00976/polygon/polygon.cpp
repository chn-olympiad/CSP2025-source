#include<bits/stdc++.h>
using namespace std;
strong a;
int n;
int cnt = 0;
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout); 
	for(int i = 0,i<=n,i++) 
	{
		if(a[i]+a[i+1]+a[i+2]=a[i+2] * 2 )
		{
		cnt++;
     	}
	}
	for(int i = 0,i<=n,i++)
	{
	    if(a[i]+a[i+1]+a[i+2]+a[i+3]=a[i+3] * 2)
    	{
		cnt++;
    	}
   	}
   	for(int i = 0,i<=n,i++)
	{
	    if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]=a[i+4] * 2)
    	{
		cnt++;
    	}
   	}
	cout << cnt;
	return 0;
}

