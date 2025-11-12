#include<bits/stdc++.h>
using namespace std;
long long a[100005][8],ans=0,num[5];
struct node
{
	int sm,cho;
} scho[100005];
int cmp(node a,node b)
{
	return a.sm<b.sm;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=num[1]=num[2]=num[3]=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				scho[i].cho=1;
				if(a[i][2]>=a[i][3]) scho[i].sm=a[i][1]-a[i][2];
				else scho[i].sm=a[i][1]-a[i][3];
			}
			else if(a[i][2]>=a[i][3])
			{
				scho[i].cho=2;
				if(a[i][1]>=a[i][3]) scho[i].sm=a[i][2]-a[i][1];
				else scho[i].sm=a[i][2]-a[i][3];
			}
			else
			{
				scho[i].cho=3;
				if(a[i][1]>=a[i][2]) scho[i].sm=a[i][3]-a[i][1];
				else scho[i].sm=a[i][3]-a[i][2];
			}
			num[scho[i].cho]++;
			ans+=a[i][scho[i].cho];
		}
		for(i=1;i<=3;i++) if(num[i]*2>n) break;
		if(i==4) cout<<ans<<endl;
		else
		{
//			cout<<i<<" "<<num[i]<<" "<<ans<<endl;
			sort(scho+1,scho+n+1,cmp);
//			cout<<scho[1].sm<<endl;
			for(j=1;j<=n&&num[i]*2>n;j++)
			{
				if(scho[j].cho==i)
				{
					num[i]--;
					ans-=scho[j].sm;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
