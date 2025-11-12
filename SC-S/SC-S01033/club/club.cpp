#include <bits/stdc++.h>
#define ll long long
#define Int __int128
#define rep(i , a , b) for (int i = (a); i <= (b); i++)
#define drep(i , a , b) for (int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef pair<int , int> pii;
const int maxn = 1e5+5;
int n , m , a[maxn][4];
vector<pii>v[maxn],v2;
ll ans;
void Solve()
{
	ans = 0;
	memset(a , 0 , sizeof(a));
	v2.clear();
	rep(i , 1 , 3)v[i].clear();
	cin >> n;
	rep(i , 1 , n) rep(j , 1 , 3)cin >> a[i][j];
	rep(i , 1 , n)
	{
		int p = 0;
		rep(j , 1 , 3) if (a[i][j] > a[i][p])p=j;
		v[p].pb({a[i][p] , i});
	}
	rep(i , 1 , 3)sort(v[i].begin(),v[i].end() , greater<pii>());
	int now = 0;
	rep(i , 1 , 3) if (v[i].size() > v[now].size())now=i;
	rep(i , 1 , 3) for (auto x : v[i])ans+=x.first;
	if (v[now].size() > n/2)
	{
		rep(i , 0 , v[now].size()-1)
		{
			pii p = v[now][i];
			int x=p.second;
			int tmp = 0;
			rep(j , 1 , 3) if (a[x][j] > a[x][tmp] && j != now)tmp=j;
			v2.pb({a[x][tmp]-a[x][now] , x});
		}
		sort(v2.begin(),v2.end(),greater<pii>());
		rep(i , 0 , v2.size()-n/2-1)ans+=v2[i].first;
	}
	cout << ans << "\n";
	return;
	
}
signed main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin >> T;
	while(T--)Solve();
	return 0;
}
// 15:00