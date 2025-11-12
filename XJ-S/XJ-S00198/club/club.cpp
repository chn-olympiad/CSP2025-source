#include<bits/stdc++.h>
using namespace std;
int a[100010][4],cnt[11],b[100010][4];
int max1[100010],max2[100010],c[100010];
vector<int> v[4];
bool cmp(int x,int y)
{
	return c[x]<c[y];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		v[1].clear();
		v[2].clear();
		v[3].clear();
		cnt[1]=cnt[2]=cnt[3]=0;
		int n;
		scanf("%d",&n);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			b[i][1]=a[i][1];
			b[i][2]=a[i][2];
			b[i][3]=a[i][3];
			sort(b[i]+1,b[i]+4);
			if(a[i][1]==b[i][3])
			{
				cnt[1]++;
				v[1].push_back(i);
			}
			else if(a[i][2]==b[i][3])
			{
				cnt[2]++;
				v[2].push_back(i);
			}
			else
			{
				cnt[3]++;
				v[3].push_back(i);
			}
			max1[i]=b[i][3];
			max2[i]=b[i][2];
			c[i]=max1[i]-max2[i];
			ans+=max1[i];
		}
		if(cnt[1]>n/2)
		{
			sort(v[1].begin(),v[1].end(),cmp);
			for(int i=0;i<cnt[1]-n/2;i++)
			{
				ans-=c[v[1][i]];
			}
		}
		else if(cnt[2]>n/2)
		{
			sort(v[2].begin(),v[2].end(),cmp);
			for(int i=0;i<cnt[2]-n/2;i++)
			{
				ans-=c[v[2][i]];
			}
		}
		else if(cnt[3]>n/2)
		{
			sort(v[3].begin(),v[3].end(),cmp);
			for(int i=0;i<cnt[3]-n/2;i++)
			{
				ans-=c[v[3][i]];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

