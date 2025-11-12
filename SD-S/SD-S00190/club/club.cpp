#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=1e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int T;
int n;
int a[N][3];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=0;j<=2;j++) cin>>a[i][j];
	int cnt[3]={0,0,0};
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int maxn=max({a[i][0],a[i][1],a[i][2]});
		ans+=maxn;
		if(maxn==a[i][0]) cnt[0]++;
		else if(maxn==a[i][1]) cnt[1]++;
		else cnt[2]++;
	}
	int maxn=max({cnt[0],cnt[1],cnt[2]});
	if(maxn<=n/2)
	{
		cout<<ans<<endl;
		return ;
	}
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		int num=max({a[i][0],a[i][1],a[i][2]});
		if(num==a[i][0]) 
		{
			if(maxn==cnt[0]) q.push(-a[i][0]+max(a[i][1],a[i][2]));
		}
		else if(num==a[i][1])
		{
			if(maxn==cnt[1]) q.push(-a[i][1]+max(a[i][0],a[i][2]));
		}
		else
		{
			if(maxn==cnt[2]) q.push(-a[i][2]+max(a[i][0],a[i][1]));
		}
	}
	while(maxn>n/2) ans+=q.top(),q.pop(),maxn--;
	cout<<ans<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) solve();
	return 0;
}
