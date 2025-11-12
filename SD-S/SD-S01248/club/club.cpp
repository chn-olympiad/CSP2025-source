#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,cnt[5],a[100005][5],ans;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >q1,q2,q3;
void solve(ll op)
{
	if(op==1)
	{
		while(cnt[1]>n/2)
		{
			ans-=q1.top().first;
//			cout<<q1.top().first<<" "<<cnt[1]<<"\n";
			q1.pop();
			cnt[1]--;
		}
	}
	if(op==2)
	{
		while(cnt[2]>n/2)
		{
			ans-=q2.top().first;
			q2.pop();
			cnt[2]--;
		}
	}	
	if(op==3)
	{
		while(cnt[3]>n/2)
		{
			ans-=q3.top().first;
			q3.pop();
			cnt[3]--;
		}
	}		
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++) cin>>a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			int ma=-2e9,ma1=-2e9,maid=0;
			for(int j=1;j<=3;j++)
			{
				if(ma<a[i][j]) ma1=ma,maid=j,ma=a[i][j];
				else if(a[i][j]>ma1) ma1=a[i][j];
			}
			cnt[maid]++;
			ans+=ma;
			if(maid==1) q1.push({ma-ma1,i});
			else if(maid==2) q2.push({ma-ma1,i});
			else q3.push({ma-ma1,i});
		}
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			cout<<ans<<"\n";
			continue;
		}
		if(cnt[1]>n/2) solve(1);
		else if(cnt[2]>n/2) solve(2);
		else if(cnt[3]>n/2) solve(3);
		cout<<ans<<"\n";
	}
	return 0;
}
//	Ren5Jie4Di4Ling5%
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

//10
//6839 5455 15586
//11767 12919 2643
//13775 8904 19938
//13717 11997 15170
//13707 2404 17497
//3471 2462 8073
//18467 14346 18663
//13582 4839 15785
//11875 7476 12308
//8568 3134 18522
