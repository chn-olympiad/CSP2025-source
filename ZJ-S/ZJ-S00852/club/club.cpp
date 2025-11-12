#include<bits/stdc++.h>
using namespace std;
int n,t;
long long a[200100][5];
int dfs(int u,int l,int i1,int i2,int i3,long long cnt)
{
	long long d1,d2,d3;
	if(i1 == n/2+1) return 0;
	if(i2 == n/2+1) return 0;
	if(i3 == n/2+1) return 0;
	if(u == n) return a[u][l];
	if(i1 <= n/2) d1 = dfs(u+1,1,i1+1,i2,i3,a[u+1][1]);
	if(i2 <= n/2) d2 = dfs(u+1,2,i1,i2+1,i3,a[u+1][2]);
	if(i3 <= n/2) d3 = dfs(u+1,3,i1,i2,i3+1,a[u+1][3]);
	cnt+=max(max(d1,d2),d3);
	return cnt;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		long long ans1 = dfs(1,1,1,0,0,a[1][1]);
		long long ans2 = dfs(1,2,0,1,0,a[1][2]);
		long long ans3 = dfs(1,3,0,0,1,a[1][3]);
		cout<<max(ans1,max(ans2,ans3))<<endl;
	}
	return 0;
}	