#include <bits/stdc++.h>
using namespace std;
int t,n;
long long a[100005][4],b[100005],sum[4],k,l[100005],cnt,ans;
vector<long long> e[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		for(int i=1;i<=3;i++)
			e[i].clear();
		scanf("%d",&n);ans=0;
		sum[1]=0;sum[2]=0;sum[3]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
			k=max(max(a[i][1],a[i][2]),a[i][3]);
			if(k==a[i][1])sum[1]++,e[1].push_back(i);
			else if(k==a[i][2])sum[2]++,e[2].push_back(i);
			else sum[3]++,e[3].push_back(i);
			ans+=k;
			sort(a[i]+1,a[i]+4);
			b[i]=a[i][3]-a[i][2];
		}
		if(sum[1]<=n/2&&sum[2]<=n/2&&sum[3]<=n/2)
			printf("%lld\n",ans);
		else
		{
			if(sum[1]>n/2)k=1;
			else if(sum[2]>n/2)k=2;
			else k=3;
			cnt=0;
			for(int i=0;i<e[k].size();i++)
				l[++cnt]=b[e[k][i]];
			sort(l+1,l+cnt+1);
			for(int i=1;i<=sum[k]-n/2;i++)
				ans-=l[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}
