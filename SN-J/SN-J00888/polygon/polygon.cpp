#include<bits/stdc++.h>
#include<fstream>
std::fstream cin("polygon.in");
std::fstream cout("polygon.out");
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int a[5005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
	   int z;
	   z=a[i]+a[i+1]+a[i+2];
	   int c;
	   for(int i=n;i>=3;i--)
	   {
	   	    c=a[i];
	   	    if(a[i]<a[i-1])
	   	    {
			 	c=a[i-1];
		    }
	   } 
		if(z>2*c)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
