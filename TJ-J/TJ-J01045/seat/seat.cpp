#include <iostream>
#include <algorithm> 
using namespace std;
int main()
{
	
	int n,m,a[100]={},b[100]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		
		cin>>a[i];
	}
	int c=a[1];
	sort(a,a+n);
	for(int i=n*m;i>=1;i--)
	{
		b[n*m-i]=a[i];
		
	}
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]==c)
		{
			if(i==1||i==n*m)
			{
				if(i==1)
				{
					cout<<n<<" "<<m;
				}
				else
				{
					cout<<1<<" "<<1;
				}
			}
			else
			{
				if(i%m!=0)
				{
					cout<<i%m+1<<" "<<i%m+1;
				}
				else
				{
					cout<<i%m<<" "<<i%m-1;
				}	
			}
		}
	
	}
  return 0;	
} 



 
