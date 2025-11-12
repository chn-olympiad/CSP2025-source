#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5;
int n,cnt[3];
ll a[3][N + 5],b[3][N + 5],ans;
priority_queue <ll> q[3];
void solve()
{
	cin>>n;
	cnt[0] = cnt[1] = cnt[2] = 0;
	ans = 0;
	while(!q[0].empty())q[0].pop();
	while(!q[1].empty())q[1].pop();
	while(!q[2].empty())q[2].pop();
	for(int i = 1;i <= n;i++)
	{
		cin>>a[0][i]>>a[1][i]>>a[2][i];
		int mx = max(a[0][i],max(a[1][i],a[2][i]));
		if(mx == a[0][i])
		{
			b[0][++cnt[0]] = -min(mx - a[1][i],mx - a[2][i]);
			ans += mx;
		}
		else if(mx == a[1][i])
		{
			b[1][++cnt[1]] = -min(mx - a[0][i],mx - a[2][i]);
			ans += mx;
		}
		else if(mx == a[2][i])
		{
			b[2][++cnt[2]] = -min(mx - a[0][i],mx - a[1][i]);
			ans += mx;
		}
	}
	for(int j = 0;j <= 2;j++)
	{
		sort(b[j] + 1,b[j] + cnt[j] + 1);
		while(cnt[j] > n / 2)ans += b[j][cnt[j]--];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
}