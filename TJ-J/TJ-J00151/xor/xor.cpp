#include<bits/stdc++.h>
using namespace std;
int a[50005]={3},b,n,num,ans,sum,liu,ming,hao;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			num++;
		}
		if(a[i]==1)
		{
			liu++;
		}
		
	}
	if(num==0)
	{
		ans=max(n/2,(n-1)/2);
	}
	else
	{
		if(b==0)
		{
			for(int i=0;i<n;i++)
			{
				sum++;		
				if(a[i+1]==a[i]){
					ans++;
					i++;
				}
				else
				{
					i+=2;
					ans++;
					if(i>=n-2)
					{
						ans--;
					}
				}
				
			}
		}
		if(b==1)
		{
			ans=liu;
			
		}
		
	}
	cout<<ans;


	return 0;	
}
