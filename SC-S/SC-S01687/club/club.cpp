#include <bits/extc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 1e5 + 5,inf = 0x3f3f3f3f3f3f3f3f;
struct Node
{
	int mx,smx,mxid;
	void init()
	{
		mx = smx = -inf;
		for(int i = 0,a;i < 3;i++)
		{
			cin >> a;
			if(a >= mx)
				smx = mx,mx = a,mxid = i;
			else if(a >= smx)
				smx = a;
		}
	}
	bool operator>(const Node& rhs) const
	{
		if(mx != rhs.mx)
			return mx > rhs.mx;
		return smx > rhs.smx;
	}
	bool operator<(const Node& rhs) const
	{return (mx - smx) < (rhs.mx - rhs.smx);}
}rec[MAXN];
int T = 1;
int n,N,cnt[3];
inline void Solve()
{
	cin >> n;
	N = n >> 1;
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i = 1;i <= n;i++)
		rec[i].init();
	sort(rec + 1,rec + n + 1,greater<Node>());
	int ans = 0;
	for(int i = 1;i <= n;i++)
		++cnt[rec[i].mxid],ans += rec[i].mx;
	int id = -1;
	for(int i = 0;i < 3;i++)
	{
		if(cnt[i] > N)
		{
			id = i;
			break;
		}
	}
	if(id == -1)
	{
		cout << ans << '\n';
		return ;
	}
	sort(rec + 1,rec + n + 1);
	int lim = cnt[id] - N;
	for(int i = 1,num = 0;i <= n;i++)
	{
		if((rec[i].mxid == id) && (num < lim))
		{
			num++;
			ans += rec[i].smx - rec[i].mx;
		}
	}
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifndef LOCAL
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
#endif
	cin >> T;
	while(T--)
		Solve();
}