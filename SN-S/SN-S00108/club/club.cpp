#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define float double
using namespace std;
int T,n,ans;
int a[100005][3];
void dfs(int step,int n1,int n2,int sum)
{
	if(step>n)
	{
		if(n2<=n/2 && n1<=n/2 && n-n1-n2<=n/2)
			ans=max(ans,sum);
		return;
	}
//	if(n1>n/2 || n2>n/2 || n-n1-n2>n/2)
//		return;
		
	dfs(step+1,n1+1,n2,sum+a[step][1]);
	dfs(step+1,n1,n2+1,sum+a[step][2]);
	dfs(step+1,n1,n2,sum+a[step][3]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
