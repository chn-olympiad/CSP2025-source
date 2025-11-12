#include<bits/stdc++.h>
using namespace std;
const int no=-1;
int n,k,a[10005],f[1005][1005],ans,l,flag[1005];
bool check(int le,int ri)
{
	for(int i=le;i<=ri;i++)
	{
		if(flag[i])return 0;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		f[i][i]=a[i];
		if(a[i]==k)
		{
			ans++;
			flag[i]=1;
		}
	}
	for(int len=2;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			int ks=(i+j)/2;
			f[i][j]=f[i][ks]^f[ks+1][j];
			if(f[i][j]==k&&check(i,j))
			{
				ans++;
				for(int o=i;o<=j;o++)
				{
					flag[o]=1;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}