#include<bits/stdc++.h>
using namespace std;
int n,a[100005][4],b1[100005],b2[100005],b3[100005],num[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;
	cin>>_;
	while(_--)
	{
		scanf("%d",&n);
		num[1]=num[2]=num[3]=0;
		long long sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				b1[++num[1]]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
				sum+=a[i][1];
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				b2[++num[2]]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
				sum+=a[i][2];
			}
			else
			{
				b3[++num[3]]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
				sum+=a[i][3];
			}
		}
		if(num[1]>n/2)
		{
			sort(b1+1,b1+num[1]+1);
			for(int i=1;i<=num[1]-n/2;i++)
			{
				sum-=b1[i];
			}
		}
		if(num[2]>n/2)
		{
			sort(b2+1,b2+num[2]+1);
			for(int i=1;i<=num[2]-n/2;i++)
			{
				sum-=b2[i];
			}
		}
		if(num[3]>n/2)
		{
			sort(b3+1,b3+num[3]+1);
			for(int i=1;i<=num[3]-n/2;i++)
			{
				sum-=b3[i];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 