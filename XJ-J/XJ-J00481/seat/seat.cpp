#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,shu=0,a1,im,i;
	cin>>a>>b;
	int c[a*b];
	if(a%2==0)
	{
		for( i=1;i<=a/2;i++)
    	{
	    	for(int j=1;j<=b;j++)
	     	{
	    		cin>>c[shu];
	    		if(c[0]>c[shu])
	        	{
	        	    if(j=b)
	        	    {
	        	    	cout<<i<<" "<<j+1;
					}
		     	    cout<<i<<" "<<j;
		     	    return 0; 
	        	}
	    		shu++;
	    	}
	    	for(int j=b;j>=0;j--)
	     	{
		    	cin>>c[shu];
		    	if(c[0]>c[shu])
	        	{
		     	    cout<<i<<" "<<b+2-j;
		     	    return 0;
	        	}
		    	shu++;
	    	}
    	}
	}
	else if(a%2==1)
	{
		for( i=1;i<=a/2-1;i++)
    	{
	    	for(int j=1;j<=b;j++)
	     	{
	    		cin>>c[shu];
	    		if(c[0]>c[shu])
	        	{
	        		if(j=b)
	        	    {
	        	    	cout<<i<<" "<<j+1;
					}
		     	    cout<<2*i<<" "<<j;
		     	    return 0;
	        	}
	    		shu++;
	    	}
	    	for(int j=b;j>=0;j--)
	     	{
		    	cin>>c[shu];
		    	if(c[0]>c[shu])
	        	{
	        		if(j=b)
	        	    {
	        	    	cout<<i<<" "<<j+1;
					}
		     	    cout<<i*2<<" "<<b+2-j;
		     	    return 0;
	        	}
		    	shu++;
	    	}
    	}
    	for(int j=1;j<=b;j++)
	     	{
	    		cin>>c[shu];
	    		if(c[0]>c[shu])
	        	{
	        		if(j=b)
	        	    {
	        	    	cout<<i<<" "<<j+1;
					}
		     	    cout<<i*2<<" "<<j;
		     	    return 0;
	        	}
	    		shu++;
	    	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
