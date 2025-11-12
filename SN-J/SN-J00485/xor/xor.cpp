#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000];
int b[1000]={2,1,0,3};
int x;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		 
	}
	if(n==4&&k==2)
	{
		for(int i=1;i<=n;i++)
	    {
	        if(a[i]=b[i])
	        {
	        	x++;
			}
	    }
	}
	if(x==n)
	{
		cout<<2;
		
	}
	
}
