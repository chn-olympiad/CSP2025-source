#include<iostream>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int n,t,a[100005],rmax=0,zmax=0,b/*一部*/,c/*二部*/,d/*三部*/;
	short pos=0;
	cin>>t;
	cin>>n;
	for(int i=1;i<=t;i++)
	{
		for(int k=1;k<=n;k++)
		{
	    	for(int j=1;j<=3;j++)
	    	{
	    		cin>>a[j];
			}
	    }
	}
	for(int j=1;j<=t;j++)
	{
 	 for(int i=1;i<=n;i++)
	 {
	    	for(int k=1;k<=3;k++)
	    	{
	    		if(a[j]>a[j+1]&&a[j]>a[j-1])
	    		{
	    		    rmax=a[j];
	    		    pos=j;
	    		}
			}
	 }
    }
    cout<<pos;
	return 0;
}
