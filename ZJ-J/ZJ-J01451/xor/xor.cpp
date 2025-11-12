#include<bits/stdc++.h>
using namespace std;
int n,q,ans,a[1010],f[1010][1010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i][i]==q)
		{
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=f[i][j-1]^a[j];
			if(f[i][j]==q)
			{
				ans++;
				i=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

