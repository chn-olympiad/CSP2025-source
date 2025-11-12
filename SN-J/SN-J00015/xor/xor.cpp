//SN-J00015 QIAOYUXIAO
#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
int v[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int fl=0;
	if(k>1)fl=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)fl=1;
	}
	int x=0,flag=0;
	if(n>199999&&fl==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)ans++;
		}
		cout<<ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j>=1;j--)
			{
				if((x^a[j])==k)
				{
					int flag=0;
					for(int l=j;l<=i;l++)
					{
						if(v[l]==1||v[i-l+j]==1)
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						ans++;
						v[i]=1;v[j]=1;
						break;
					}
				}
				else
				{
					x=(x^a[j]);
				}
			}
			x=0;
		}
		cout<<ans;
	}
	return 0;
}
