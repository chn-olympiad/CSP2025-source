#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+10;
int a[N][5], num[5];
int n, ans=0;
void dfs(int x, int v)
{
	if(x>n)
	{
		ans=max(ans, v);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]<n/2)
		{
			num[i]++;
			dfs(x+1, v+a[x][i]);
			num[i]--;
		}
	}
}
bool checkA()
{
	for(int i=1;i<=n;i++)
		if(a[i][2]||a[i][3]) return false;
	return true;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(num, 0, sizeof num);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		if(checkA())
		{
			vector<int> v;
			for(int i=1;i<=n;i++)
				v.push_back(a[i][1]);
			sort(v.begin(), v.end(), greater<int>());
			int cnt=0;
			for(int i=0;i<v.size()&&cnt<n/2;i++)
			{
				ans+=v[i];
				cnt++;
			}
			cout<<ans<<'\n';
			continue;
		}
		dfs(1, 0);
		cout<<ans<<'\n';
	}
	return 0;
}
