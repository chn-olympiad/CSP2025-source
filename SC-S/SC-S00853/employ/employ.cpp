#include<bits/stdc++.h>

using namespace std;

#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

const int N = 515;


char str[N];
int arr[N];

int vis[N];
int n,m;
int now[N];

int ans = 0;

void dfs(int dep)
{
	if(dep == n+1)
	{
//		for(int i = 1;i<=n;i++)
//		{
//			cout<<now[i]<<' ';
//		}
//		cout<<endl;
		int cnt = 0;
		for(int i = 1;i<=n;i++)
		{
//			cout<<i<<' '<<i-1-cnt<<' '<<arr[now[i]]<<endl;
			if(i-1-cnt >= arr[now[i]])continue;
			if(str[i] == '1')
			{
				cnt++;
			}
		}
		if(cnt >= m)
		{
			ans++;
		}
//		cout<<cnt<<endl;
		return ;
		
	}
	for(int i = 1;i<=n;i++)
	{
		if(vis[i] == 1)continue;
		now[dep] = i;
		vis[i] = 1;
		dfs(dep+1);
		vis[i] = 0;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>str[i];
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	dfs(1);

	cout<<ans<<endl;

	return 0;
 }
