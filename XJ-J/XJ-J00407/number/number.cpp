#include <iostream>
using namespace std;
int s[1000005],n[1000005];
int main()
{
	for(int i=1;i<=1000005;i++)
	{
		cin>>s[i];
	
	}
	for(int i=1;i<=s.length();i++)
	{
		if(s[i]==0 or 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 )
		{
			n[i]+=s[i];
		}
	}	
	for(int i=1;i<=n.length;i++)
	{
	  
		int max=0;
		
		for(int i=1;i<=n.length;i++)
		{
			if(n[i]>max)
			{
				max=n[i];
			}
		}
		cout<<max;
		
	}
	
	return 0;
 } 
