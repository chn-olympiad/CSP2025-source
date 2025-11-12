#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],ans,g=2;
bool vis[10005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			vis[i]=1;
		}
	}
	while(g<n)
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i]!=1)
			{
				int h=a[i];
				for(int j=i+1;j<=i+g;j++)
				{

					if(vis[j]==1)
					{
						for(int kk=i;kk<=j;kk++)
						{
							vis[kk]=1;
						}
						i=j+1;
						break;
					}
					h^=a[j];
					if(h==k)
					{
						for(int kk=i;kk<=j;kk++)
						{
							vis[kk]=1;
						}
						ans++;
						i=j+1;
						break;
					}
				}
			}
		}
		g++;
	}
	cout<<ans;
	return 0;
}
