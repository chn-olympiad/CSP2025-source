#include<bits/stdc++.h>
using namespace std;
int t,n,pan;
long long ans;
struct shh
{
	int shu,id,dep;
};
shh a[6000005];
bool cmp(shh x,shh y)
{
	return x.shu>y.shu;
}
int vis[200005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		for(int i=1;i<=200000;i++)
		{
			vis[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[3*i-2].shu>>a[3*i-1].shu>>a[3*i].shu;
			a[3*i-2].id=i; a[3*i-1].id=i; a[3*i].id=i;
			a[3*i-2].dep=1; a[3*i-1].dep=2; a[3*i].dep=3;
			if(a[3*i-1].shu!=0||a[3*i].shu!=0) pan=1;
		}
		sort(a+1,a+1+3*n,cmp);
		if(pan==0)
		{
			int cnt=0;
			for(int i=1;i<=3*n;i++)
			{
				if(cnt>=(n/2)) break;
				if(a[i].dep==1&&vis[a[i].id]==0&&cnt<(n/2)) 
				{
					ans+=a[i].shu;
					cnt++;
					vis[a[i].id]=1;
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			int dp[4];
			for(int i=1;i<=3;i++) dp[i]=0;
			for(int i=1;i<=n*3;i++)
			{
				if(vis[a[i].id]==1||dp[a[i].dep]>=(n/2))
				{
					continue;
				}
				ans+=a[i].shu;
				dp[a[i].dep]++;
				vis[a[i].id]=1;
			}
			cout<<ans<<endl;
		}
	} 
	return 0;
}
