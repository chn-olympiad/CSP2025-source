#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j,k,n,m,s=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				s++;
			}
			
		}
		cout<<s; 
		return 0;
	}  
	if(k==1)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				s++;
			}
			
		}
		cout<<s; 
		return 0;
	} 
	if(k==0&&n<=10)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<1;
				return 0;
			}	
		}		
	} 
	return 0;
}
