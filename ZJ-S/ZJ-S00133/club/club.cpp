#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[4],ans,f;
int dx[4]={0,2,1,1},dy[4]={0,3,3,2};
int a[10005][4];
struct node
{
	int num[10005],id[100005];
}sum[4];
int p(int a,int b,int c)
{
	if(a>b)
	{
		if(a>c)
			return 1;
		else 
			return 3;
	}
	else
	{
		if(b>c)
			return 2;
		else
			return 3;
	}
}
int q(int a,int b,int c)
{
	if(a>b)
		return dx[c];
	else
		return dy[c];
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=0;
		for(int i=1;i<=3;i++)
			cnt[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			f=p(a[i][1],a[i][2],a[i][3]);
			sum[f].num[++cnt[f]]=a[i][f];
			sum[f].id[cnt[f]]=i;
		}
		for(int i=1;i<=3;i++)
		{
			sort(sum[i].num+1,sum[i].num+cnt[i]+1,cmp);
			if(cnt[i]>n/2)
				for(int j=n/2+1;j<=cnt[i];j++)
				{	
					f=q(a[sum[i].id[j]][dx[i]],a[sum[i].id[j]][dy[i]],i);
					sum[f].num[++cnt[f]]=a[sum[i].id[j]][f];
					sum[i].num[j]=0;
				}		
		}
		for(int i=1;i<=3;i++)
			for(int j=1;j<=cnt[i];j++)
				ans+=sum[i].num[j];
		cout<<ans<<"\n";
	}
	return 0;
}