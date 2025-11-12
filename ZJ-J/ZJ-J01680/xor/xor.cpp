#include<bits/stdc++.h>
using namespace std;
int n,g,a[1000005],ans,cnt,vis[1000005],flag;
int main()
{
	freopen("xor.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>g;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			flag=0;
			cnt=0;
			for(int k=i;k<=j;k++)
			{
				if(vis[k]==1)
				{
					flag=1;
					break;
				}
				cnt=cnt^a[k];
			}
			if(flag==0)
			{
				if(cnt==g)
				{
					for(int k=i;k<=j;k++)
					{
						vis[k]=1;
					}
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}