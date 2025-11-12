#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000006],b[1000004],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			ans+=1;
			else
			{
				if(a[i]==a[i+1])
				{
				ans+=1;
				i=i+1;	
				}
				
		}
		}
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			ans+=1;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
	b[i]=b[i-1]^a[i];
	}

	for(int q=1;q<=n;q++)
	{
		int ll=0;
		for(int i=q;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if((b[j]^b[i-1])==k)
				{
					i=j+1;
					j=j;
					ll+=1;
				}
			}
		}	
	ans=max(ans,ll);
	}
	
	cout<<ans;
	return 0;
}
