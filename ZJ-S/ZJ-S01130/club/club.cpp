#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int sumone=0;
int sumtwo=0;
int sumthree=0;
long long max1[100005];
long long max2[100005];
long long max3[100005];
int c,s,p;
int wjm=0;
int t,n;
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
 
 
   cin>>t;
   int x=t;
   while(x>0)
  {
  	cin>>n;
  	int map=1;
  
  	for(int i=1;i<=n*3;i++)
	{
	  	cin>>a[i];
	} 
    for(int i=1;i<=n;i++)
    {
    	
    	c=a[map];s=a[map+1];p=a[map+2];
		sort(a+map,a+map+3);
		if(a[map+2]==c)
		{
			sumone++;
			max1[i]=a[map+2];
			max2[i]=a[map+1];
			max3[i]=a[map];
			
		}
        else if(a[map+2]==s)
        {
        	sumtwo++;
        	max1[i]=a[map+2];
			max2[i]=a[map+1];
			max3[i]=a[map];
        
		}
		else if(a[map+2]==p)
		{
			sumthree++;
			max1[i]=a[map+2];
			max2[i]=a[map+1];
			max3[i]=a[map];
			
		}
		map=map+3;
		
		
		
		
		
	}
	for(int i=1;i<=n;i++)
	{
		wjm=wjm+max1[i];
	}
	cout<<wjm;
    x--;
  }
  	
	
	
  return 0;
} 
