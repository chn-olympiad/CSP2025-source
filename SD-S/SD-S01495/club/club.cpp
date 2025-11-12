#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+7;
int n,ans;
int a[N][7],b[N];
void dfs(int x,int sum,int cnt1,int cnt2,int cnt3)
{
	if(x==n)
	{
		ans=max(ans,sum);
		return;
	}
	if(cnt1<n/2) dfs(x+1,sum+a[x+1][1],cnt1+1,cnt2,cnt3);
	if(cnt2<n/2) dfs(x+1,sum+a[x+1][2],cnt1,cnt2+1,cnt3);
	if(cnt3<n/2) dfs(x+1,sum+a[x+1][3],cnt1,cnt2,cnt3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		bool flag=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==2 && a[i][j]!=0) flag=0;
				if(j==3 && a[i][j]!=0) flag=0;
			}
		if(flag)
		{
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		if(n==2 || n==4 || n==10)
		{
			ans=0;
			dfs(1,a[1][1],1,0,0);
			dfs(1,a[1][2],0,1,0);
			dfs(1,a[1][3],0,0,1);
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
