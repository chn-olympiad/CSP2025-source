#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int T;
int n;
int a[N][5],u[5],v[N];
long long ans,cnt;
void dfs(int now,long long tot)
{
	if(now == n + 1)
	{
		ans = max(tot,ans);
//		return ;
	}
	for(int i = 1;i <= 3;i++)
	{
		if(u[i] == n / 2) continue;
		if(v[now]) continue;
		cout<<cnt++<<endl;
		u[i]++;
		dfs(now + 1,tot + a[now][i]);
		u[i]--;
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
//		memset!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		memset(u,0,sizeof(u));
		cin>>n;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= 3;j++)
			{
				cin>>a[i][j];
			}
		}
		ans = 0;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
