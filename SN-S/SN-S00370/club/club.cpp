#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int b[100005];
int c[100005];
int ans=0;
void dfs(int t,int s1,int s2,int s3,int cnt1,int cnt2,int cnt3)
{
	if(t==n+1)
	{
		if(s1>n/2 || s2>n/2 || s3>n/2)
		{
			return;
		}
		ans=max(ans,cnt1+cnt2+cnt3);
		return;
	}
	dfs(t+1,s1+1,s2,s3,cnt1+a[t],cnt2,cnt3);
	dfs(t+1,s1,s2+1,s3,cnt1,cnt2+b[t],cnt3);
	dfs(t+1,s1,s2,s3+1,cnt1,cnt2,cnt3+c[t]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=20)
		{
			dfs(1,0,0,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+1+n);
		for(int i=n/2;i<=n;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<'\n';
		
	}
	return 0;
}
