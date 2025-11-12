//李倏嘉 SN-S00323 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,cnt[3],b[N];
pair<int,int>a[N][3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int sum=0,tot=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][0].first,&a[i][1].first,&a[i][2].first);
			a[i][0].second=0,a[i][1].second=1,a[i][2].second=2,sort(a[i],a[i]+3),sum+=a[i][2].first,cnt[a[i][2].second]++;
		}
		if(max({cnt[0],cnt[1],cnt[2]})<=n/2)printf("%d\n",sum);
		else
		{
			int x=0;
			if(cnt[0]>n/2)x=0;
			if(cnt[1]>n/2)x=1;
			if(cnt[2]>n/2)x=2;
			for(int i=1;i<=n;i++)if(a[i][2].second==x)b[++tot]=a[i][2].first-a[i][1].first;
			sort(b+1,b+tot+1);
			for(int i=1;i<=cnt[x]-n/2;i++)sum-=b[i];
			printf("%d\n",sum);
		}
	}
	return 0;
}

