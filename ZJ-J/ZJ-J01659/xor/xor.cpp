#include<bits/stdc++.h>
using namespace std;
int n,k,a[1111111],vis[1111111],t=0,ans;
int main()
{
	freopen(xor.in,"r",stdin);
	freopen(xor.out,"w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0) ans++;
			if(a[i]==1&&a[i+1]==1)
			{
				ans++;
				i++;	
			}	
		}	
	}
	else if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) ans++;
		}
	}
	else
	{
		for(int l=1;l<=n;l++)
		{
			for(int r=l;r<=n;r++)
			{
				int ss=0;
				for(int i=l;i<=r;i++)
				{
					if(vis[i]==1) break;
					ss^=a[i];
				}
				if(ss==k)
				{
					ans++;
					vis[l]=1;
					vis[r]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
