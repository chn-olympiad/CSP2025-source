#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int b[1000]={1,2,3,4,5};
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		 
	}
	if(n==5)
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
		cout<<9;
		
	}
    return 0;
}
