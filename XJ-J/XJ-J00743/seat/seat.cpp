#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
int n,m;
cin>>n>>m;
int cj[(n*m)]={0};
for(int a=0;a<(n*m);a++)
    cin>>cj[a];
int x=cj[0];
sort(cj,cj+(n*m));
int xb=0,ans;
int arr[n][m]={0};
if(n==1)
{
	for(int a=0;a<m;a++)
	{
	    if(cj[a]==x)
	        ans=a+1;
	}
	cout<<ans<<" 1";
	
}else if(m==1)
{
	
	for(int a=0;a<n;a++)
	{
	    if(cj[a]==x)
	        ans=a+1;
	}
	cout<<"1 "<<ans;
}
else
	cout<<m<<" "<<n; 
return 0;
}
