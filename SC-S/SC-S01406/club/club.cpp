#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair <int , int>
#define pb pushback
#define ll long long
#define ull unsigned long long
#define fastio ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
using namespace std;
const int MAXN = 1e5 + 10 , INF = 0x3f3f3f3f;
struct node
{
	int id;
	pii val[3];//fi为属性编号，se为属性的值
	bool operator < (const node &x) const
	{
		return val[1].se - val[0].se < x.val[1].se - x.val[0].se;
	}
};
bool cmp(pii &x , pii &y) {return x.se > y.se; }
int T , n , lim;
ll ans;
node a[MAXN];
priority_queue <node> q[3];
void put_node(node now)
{
	int nowpos = now.val[0].fi;
	if(q[nowpos].size() < lim)
	{
		q[nowpos].push(now);
		ans += now.val[0].se;
	}
	else
	{
		q[nowpos].push(now) , ans += now.val[0].se;
		node tmp = q[nowpos].top();
		q[nowpos].pop();
		ans -= tmp.val[0].se;
		swap(tmp.val[0] , tmp.val[1]) , swap(tmp.val[1] , tmp.val[2]);
		put_node(tmp);
	}
	return;
}
int main()
{
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	fastio;
	cin >> T;
	while(T--)
	{
		cin >> n;
		lim = n / 2 , ans = 0;
		for(int i = 0 ; i <= 2 ; i++) while(!q[i].empty()) q[i].pop();
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> a[i].val[0].se >> a[i].val[1].se >> a[i].val[2].se;
			a[i].val[0].fi = 0 , a[i].val[1].fi = 1 , a[i].val[2].fi = 2;
			sort(a[i].val , a[i].val + 3 , cmp);
			a[i].id = i;
		}
		for(int i = 1 ; i <= n ; i++) put_node(a[i]);
		cout << ans << '\n';
	}
	cout.flush();
	return 0;
}
