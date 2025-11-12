#include<bits/stdc++.h>
using namespace std;
int a[100000],x,y,z,b,c;
int main()
{
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t,n,ans=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=3*n;j+=3)
		{
			cin>>a[j]>>a[j+1]>>a[j+3];
			
			
		}
	}	
	for(int j=1;j+3<=n;j+=3)
	{
		for(int k=j;k<=j+2;k++)
		{
			if(a[k]>=a[k+1]&&a[k]>=a[k+2])
			{
				b++;
				if(b<=n/2)
				{
					x=x+a[k];
					a[k]=0;
					a[k+1]=0;
					a[k+2]=0;
						
					
							
				}
			}
		
			else if(a[k+1]>=a[k]&&a[k+1]>=a[k+2])
			{
				c++;
				if(c<=n/2)
				{
					y=y+a[k+1];
					a[k]=0;
					a[k+1]=0;
					a[k+2]=0;
						
						
						
				}
			}
			else
			{
				z=z+a[k+2];
			}		
		}
		cout<<x+y+z<<endl;	
	}	
	return 0;
} 
