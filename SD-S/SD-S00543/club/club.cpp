#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int a[N][3],f[N][4][N];//第i个人去第j个部门,当前人数为k时的最大指数 
int n;
int dfs(int now,int j,int r1,int r2,int r3)
{
	if (now>n) return 0;
	if (j==1 && r1>n/2) return 0;
	if (j==2 && r2>n/2) return 0;
	if (j==3 && r3>n/2) return 0;
	int ans=0;
	ans=max(ans,dfs(now+1,1,r1+1,r2,r3));
	ans=max(ans,dfs(now+1,2,r1,r2+1,r3));
	ans=max(ans,dfs(now+1,3,r1,r2,r3+1));
	return ans+a[now][j];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=3;j++)
				cin>>a[i][j];
		int ans=0;
		ans=max(ans,dfs(1,1,1,0,0));
		ans=max(ans,dfs(1,2,0,1,0));
		ans=max(ans,dfs(1,3,0,0,1));
		cout<<ans<<endl;
	}
	return 0;
}

