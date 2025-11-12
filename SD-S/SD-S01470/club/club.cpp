#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt,sum[5],ans,res,a[100005][3];
long long tt[100005];
/*pair<long long,long long>a[5];
struct per
{
	long long cz,z,id,bm;
}p[300005];
bool cmp(per a,per b)
{
	if(a.cz!=b.cz)return a.cz>b.cz;
	if(a.z!=b.z)return a.z>b.z;
	if(a.bm!=b.bm)return a.bm<b.bm;
	return a.id<b.id;
}
bool f[100005];*/
void dfs(long long now,long long s1,long long s2,long long s3,long long h)
{
	if(now>n)
	{
		ans=max(ans,h);
		return;
	}
	if(s1<n/2)dfs(now+1,s1+1,s2,s3,h+a[now][1]);
	if(s2<n/2)dfs(now+1,s1,s2+1,s3,h+a[now][2]);
	if(s3<n/2)dfs(now+1,s1,s2,s3+1,h+a[now][3]);
	return;
}
void code()
{
	ans=0;
	sum[1]=sum[2]=sum[3]=0;
	cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		sum[2]=max(sum[2],a[i][2]);
		sum[3]=max(sum[3],a[i][3]);
	}
	if(sum[2]==0&&sum[3]==0)
	{
		for(int i=1;i<=n;i++)tt[i]=a[i][1];
		sort(tt+1,tt+1+n);
		for(int i=n;i>=1;i--)
		{
			if(cnt==n/2)break;
			ans+=tt[i];
			cnt++;
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		cin>>a[1].first>>a[2].first>>a[3].first;
		a[1].second=1;
		a[2].second=2;
		a[3].second=3;
		sort(a+1,a+4);
		a[0].first=a[1].first;
		a[0].second=0;
		for(int j=3;j>=1;j--)
		{
			p[++cnt].cz=a[j].first-a[j-1].first;
			p[cnt].z=a[j].first;
			p[cnt].id=i;
			p[cnt].bm=a[j].second;
		}
	}
	sort(p+1,p+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(f[p[i].id])continue;
		if(sum[p[i].bm]==(n/2))continue;
		f[p[i].id]=1;
		ans+=p[i].z;
		sum[p[i].bm]++;
		cout<<p[i].id<<' '<<p[i].bm<<'\n';
	}
	cout<<ans<<'\n';*/
	dfs(1,0,0,0,0);
	cout<<ans<<'\n';
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)code();
	return 0;
}
