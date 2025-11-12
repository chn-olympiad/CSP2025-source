#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,ans,a[500005];
bool flag=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1) flag=0;
	}
	if(flag==1&&k==0)
	{
		printf("%d",n/2);
		return 0;
	}
	for(int t=1;t<=n;t++)
	{
		cnt=0;
		for(int i=t;i<=n;)
		{
			int sum=0;
			while((sum==0&&k==0)||(sum!=k&&i<=n))
			{
				sum^=a[i];
				i++;
			}
			cnt++;
			if(i>n) break;
		}
		ans=max(ans,cnt);
	}
	printf("%d",ans);
	return 0;
}