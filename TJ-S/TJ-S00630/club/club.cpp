#include <bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005];
long long f[5];
long long n,ans;
void dfs(long long p,long long p2,long long cnt)
{
	if(p2>n)
	{
		ans=max(ans,cnt);
		return;
	}
	for(long long i=1;i<=3;i++) 
	{
		if(p==1&&f[1]<n/2)
		{
			f[1]++;
			dfs(i,p2+1,cnt+a[p2]);
			f[1]--;
		 } 
		else if(p==2&&f[2]<n/2)
		{
			f[2]++;
			dfs(i,p2+1,cnt+b[p2]);
			f[2]--;
		 } 
		else if(p==3&&f[3]<n/2)
		{
			f[3]++;
			dfs(i,p2+1,cnt+c[p2]);
			f[3]--;
		 }
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		long long ans1=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(long long i=1;i<=n;i++)
		{
			cin >> a[i]>>b[i]>>c[i];
		}
		for(long long i=1;i<=3;i++)
		{
			ans=0;
			dfs(i,1,0);
			ans1=max(ans,ans1);
		}
		cout << ans1<<endl;
	}
	return 0;
}
